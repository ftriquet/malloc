#include <malloc.h>
#include <sys/mman.h>

t_malloc	g_malloc = {/*TINY_HEAP_SIZE, SMALL_HEAP_SIZE,*/ NULL, NULL};

int		ft_init_malloc(void)
{
	t_memblock	*cast;

	if (TINY_HEAP || SMALL_HEAP)
		return (0);
	TINY_HEAP = mmap(0, TINY_HEAP_SIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!TINY_HEAP)
		return (1);
	cast = (t_memblock *)TINY_HEAP;
	cast->size = TINY_HEAP_SIZE - BLOCK_SIZE;
	cast->next = NULL;
	cast->free = 1;
	SMALL_HEAP = mmap(0, SMALL_HEAP_SIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!SMALL_HEAP)
		return (1);
	cast = (t_memblock *)SMALL_HEAP;
	cast->size = SMALL_HEAP_SIZE - BLOCK_SIZE;
	cast->next = NULL;
	cast->free = 1;
	return (0);
}

void	*ft_alloc(t_memblock *last, size_t size, t_alloc_type type)
{
	t_memblock	*block;

	block = ft_find_block(&last, size);
	if (block && ((block->size - size) >= (BLOCK_SIZE + 8)))
		ft_split_block(block, size);
	else if (!block)
	{
		block = ft_extend_heap(last,
				(type == TINY ? TINY_HEAP_SIZE : SMALL_HEAP_SIZE));
		if (!block)
			return (NULL);
	}
	if (block)
		block->free = 0;
	return (block->data);
}

void	*ft_malloc(size_t size)
{
	if (ft_init_malloc() || size == 0)
		return (NULL);
	size = ALIGN_SIZE(size);
	if (size <= TINY_ALLOC_LIMIT)
		return (ft_alloc(TINY_HEAP, size, TINY));
	if (size <= SMALL_ALLOC_LIMIT)
		return (ft_alloc(SMALL_HEAP, size, SMALL));
	return (ft_large_alloc(size));
}
