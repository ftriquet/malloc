#include <malloc.h>
#include <stdio.h>

void	ft_merge_blocks(t_alloc_type type)
{
	if (type == TINY)
		return (ft_merge_heap(TINY_HEAP, TINY_HEAP,
				   	TINY_HEAP_SIZE, TINY_HEAP_SIZE));
	else if (type == SMALL)
		return (ft_merge_heap(SMALL_HEAP, SMALL_HEAP,
				   	SMALL_HEAP_SIZE, SMALL_HEAP_SIZE));
}


void	ft_merge_heap(int *ptr, void *heap, size_t size, size_t heap_size)
{
	if (size > 16)
	{
		ft_merge_heap(ptr + (size / 8), heap, size / 2, heap_size);
		ft_merge_heap(ptr, heap, size / 2, heap_size);
	}
	if ((void *)ptr + ptr[0] >= heap + heap_size)
		return ;
	if ((ptr[0] == ptr[ptr[0] / 4]) &&
			(ptr[1] != 1 && ptr[ptr[0] / 4 + 1] != 1))
		ptr[0] <<= 1;
}
