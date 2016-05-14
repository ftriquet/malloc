#include <malloc.h>
#include <stdlib.h>
#include <libft.h>
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

void		*ft_alloc(t_memblock *last, size_t size, t_alloc_type type)
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

void		*realloc(void *addr, size_t size)
{
	t_memblock	*block;
	t_memblock	*prev;

	if (addr == NULL)
		return (malloc(size));
	prev = ft_is_valid_block((t_memblock *)(addr - BLOCK_SIZE));
	if (prev)
	{
		block = malloc(size);
		if (block)
		{
			ft_memmove(block, addr, (prev == addr - BLOCK_SIZE) ? prev->size : prev->next->size);
			free(addr);
			return (block);
		}
	}
	return (NULL);
}

void		free(void *addr)
{
	t_memblock		*block;
	t_memblock		*prev;

	block = (t_memblock *)(addr - BLOCK_SIZE);
	prev = ft_is_valid_block(block);
	if (prev != NULL && block->free == 0)
	{
		block->free = 1;
		ft_merge_blocks(block, prev);
	}
}

t_memblock	*ft_is_valid_block(t_memblock *block)
{
	t_memblock	*tmp;
	t_memblock	*prev;

	if (block == NULL)
		return (NULL);
	if (block->size <= TINY_ALLOC_LIMIT)
		tmp = TINY_HEAP;
	else if (block->size <= SMALL_ALLOC_LIMIT)
		tmp = SMALL_HEAP;
	else
		tmp = LARGE_ALLOCS;
	prev = tmp;
	while (tmp)
	{
		if (tmp == block)
			return (prev);
		prev = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

void		ft_merge_blocks(t_memblock *block, t_memblock *prev)
{
	if (block->next == NULL)
		return ;
	while (block->next != NULL && block->next->free == 1)
	{
		block->size += block->next->size + BLOCK_SIZE;
		block->next = block->next->next;
	}
	if (block != NULL && prev != NULL && block != prev && prev->free == 1 &&
			block->free == 1)
	{
		prev->size += block->size + BLOCK_SIZE;
		prev->next = block->next;
	}
}

void		*malloc(size_t size)
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

void	dump_memory(void)
{
	t_memblock	*block;

	block = TINY_HEAP;
	ft_putendl("====TINY_HEAP===");
	while (block)
	{
		ft_printf("[%p] FREE: %d, size: %8d\n", block->data, block->free, block->size);
		block = block->next;
	}
	ft_putendl("=================");
	ft_putendl("====SMALL_HEAP===");
	block = SMALL_HEAP;
	while (block)
	{
		ft_printf("[%p] FREE: %d\n", block->data, block->free);
		block = block->next;
	}
	ft_putendl("=================");
}
