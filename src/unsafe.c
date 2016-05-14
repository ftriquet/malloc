#include <malloc.h>
#include <stdlib.h>
#include <libft.h>

void		*realloc_unsafe(void *addr, size_t size)
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

void		free_unsafe(void *addr)
{
	t_memblock		*block;
	t_memblock		*prev;

	block = (t_memblock *)(addr - BLOCK_SIZE);
	prev = ft_is_valid_block(block);
	if (prev != NULL && block->free == 0)
	{
		block->free = 1;
		if (block->size > SMALL_ALLOC_LIMIT)
			return (ft_remove_large_alloc(block, prev));
		ft_merge_blocks(block, prev);
	}
}

void		*malloc_unsafe(size_t size)
{
	if (ft_init_malloc() || size == 0)
		return (NULL);
	size = ALIGN_SIZE_8(size);
	if (size <= TINY_ALLOC_LIMIT)
		return (ft_alloc(TINY_HEAP, size, TINY));
	if (size <= SMALL_ALLOC_LIMIT)
		return (ft_alloc(SMALL_HEAP, size, SMALL));
	return (ft_large_alloc(size));
}

void		*calloc(size_t count, size_t size)
{
	void	*block;

	block = malloc(count * size);
	ft_bzero(block, count * size);
	return (block);
}

void		*reallocf(void *ptr, size_t size)
{
	void	*alloc;

	alloc = realloc(ptr, size);
	if (alloc == NULL)
		free(ptr);
	return (alloc);
}
