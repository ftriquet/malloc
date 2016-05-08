#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>

int		*ft_find_block(size_t size)
{
	if (size <= TINY_ALLOC_LIMIT)
		return (ft_get_block(TINY_HEAP, TINY_HEAP,
					size, TINY_HEAP_SIZE));
	else if (size < SMALL_ALLOC_LIMIT)
		return (ft_get_block(SMALL_HEAP, TINY_HEAP,
					size, SMALL_HEAP_SIZE));
	return (ft_large_alloc(size));
}

int		*ft_get_block(int *current, void *heap, size_t size, size_t heap_size)
{
	int		split_size;

	printf("LOOKING AT %p for %ldB, limit : %p\n", current, size, heap + heap_size);
	if ((void *)current >= (heap + heap_size))
		if (ft_extend_zone(heap))
			return (NULL);
	if ((size_t)current[0] < size || current[1] == 1)
		return (ft_get_block(current + current[0] / 4, heap, size, heap_size));
	if (current[0] == (int)size) // bonne taille
	{
		printf("RETURNING ALLOCATION OF %lu AT %p\n", size, current);
		current[1] = 1; // mark as allocated
		return (current + 2);
	}
	else
	{
		split_size = current[0] / 2;
		current[0] = split_size;
		current[split_size / 4] = split_size;
		if (current[1] == -1) //dernier block
			current[split_size / 4 + 1] = -1;
		else //block libre
			current[split_size / 4 + 1] = 0;
		current[1] = 0;
		return (ft_get_block(current, heap, size, heap_size));
	}
	return (NULL);
}

int		ft_extend_zone(void *heap)
{
	size_t	size;
	void	*heap_extension;

	if (heap == TINY_HEAP)
		size = TINY_HEAP_SIZE;
	else
		size = SMALL_HEAP_SIZE;
	heap_extension = mmap(heap + size, size,  PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (heap_extension == NULL)
	{
		errno = ENOMEM;
		return (1);
	}
	if (heap == TINY_HEAP)
		TINY_HEAP_SIZE *= 2;
	else
		SMALL_HEAP_SIZE *= 2;
	((int *)heap_extension)[0] = (int)size;
	((int *)heap_extension)[1] = 1;
	return (0);
}

int		*ft_large_alloc(size_t size)
{
	(void)size;
	return (NULL);
}
