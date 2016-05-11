#include <malloc.h>
#include <sys/mman.h>
#include <libft.h>

t_memblock	*ft_find_block(t_memblock **last, size_t size)
{
	t_memblock *b;

	b =  (t_memblock *)(g_malloc.tiny_heap);
	while (b && !(b->free && b->size >= size)) {
		*last  = b;
		b = b->next;
	}
	return (b);
}

t_memblock	*ft_extend_heap(t_memblock *last, size_t size)
{
	t_memblock	*b;

	b = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			-1, 0);
	if (b) {
		b->size = size - BLOCK_SIZE;
		b->next = NULL;
		b->free = 1;
	}
	if (last) {
		last->next = b;
	}
	return (b);
}

void		ft_split_block(t_memblock *block, size_t size)
{
	t_memblock	*new_block;

	new_block = (t_memblock *)(block->data + size);
	new_block->size = block->size - size - BLOCK_SIZE;
	new_block->next = block->next;
	new_block->free = 1;
	block->size = size;
	block->next = new_block;
}

void		*ft_large_alloc(size_t size)
{
	(void)size;
	return (NULL);
}
