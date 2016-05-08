#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <malloc.h>


void	*heap = NULL;
int		*free_blocks = NULL;

void	unmap(void)
{
	munmap(heap, HEAP_SIZE);
}

int		*ft_get_block(int *current_block, size_t size)
{
	int		split_size;

	// trop loin (heap remplie)
	if (current_block >= (int *)(heap + HEAP_SIZE))
		return (NULL);

	// block trop petit
	if (current_block[0] < (int)size)
		return (ft_get_block(current_block + current_block[0] / 4, size));

	// block occupe
	if (current_block[1] > 0)
		return (ft_get_block(current_block + current_block[0] / 4, size));

	// le block est libre

	// block de bonne taille
	if (current_block[0] == (int)size) // bonne taille
	{
		current_block[1] = 1;
		return (current_block + 2);
	}
	// block trop grand: on split et appel recursif
	else
	{
		split_size = current_block[0] / 2;
		current_block[0] = split_size;
		current_block[split_size / 4] = split_size;
		if (current_block[1] == -1) //dernier block
			current_block[split_size / 4 + 1] = -1;
		else //block libre
			current_block[split_size / 4 + 1] = 0;
		current_block[1] = 0;
		return (ft_get_block(current_block, size));
	}
	return (NULL);
}


void	*ft_malloc(size_t size)
{
	size_t	alloc_size;

	if (heap == NULL)
	{
		heap = mmap(0, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		free_blocks = (int *)heap;
		free_blocks[0] = HEAP_SIZE;
		free_blocks[1] = -1;
		atexit(&unmap);
	}

	alloc_size = ALLOC_MIN;
	size += 8;
	while (alloc_size < size)
		alloc_size <<= 2;
	return (void *)ft_get_block(free_blocks, alloc_size);
}
