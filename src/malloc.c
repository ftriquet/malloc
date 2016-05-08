#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <malloc.h>


void	*heap = NULL;
int		*free_blocks = NULL;

void	unmap(void)
{
	puts("BYE");
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
	if (current_block[1] == 1)
		return (ft_get_block(current_block + current_block[0] / 4, size));

	// le block est libre

	// block de bonne taille
	if (current_block[0] == (int)size) // bonne taille
	{
		current_block[1] = 1; // mark as allocated
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

void	ft_free(void *addr)
{
	int		*tmp;

	tmp = (int *)addr;
	tmp -= 2;
	if (tmp[1] != 1)
		return ;
	tmp[1] = 0;
}

void	ft_merge_blocks(void)
{
	return (ft_merge_block((int *)heap, HEAP_SIZE));
}

void	ft_merge_block(int *begin, size_t size)
{
	if (size > 16)
	{
		ft_merge_block(begin + (size / 8), size / 2);
		ft_merge_block(begin, size / 2);
	}
	if ((void *)begin + begin[0] >= heap + HEAP_SIZE)
		return ;
	if ((begin[0] == begin[begin[0] / 4]) &&
			(begin[1] != 1 && begin[begin[0] / 4 + 1] != 1))
		begin[0] <<= 1;
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
		alloc_size <<= 1;
	return (void *)ft_get_block(free_blocks, alloc_size);
}

void	dump_memory(void)
{
	int		*ptr;

	puts("+++++MEMORY DUMP+++++");
	ptr = (int *)heap;
	while ((void *)ptr < heap + HEAP_SIZE)
	{
		if (ptr[1] == 1)
			printf("[%p] :: size: %d, allocated\n", ptr, ptr[0]);
		else
			printf("[%p] :: size: %d, free\n", ptr, ptr[0]);
		ptr += ptr[0] / 4;
	}
	puts("+++++++++++++++++++++");
}
