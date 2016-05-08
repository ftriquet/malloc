#include <malloc.h>
#include <unistd.h>
#include <sys/mman.h>

t_malloc		g_malloc = {0, 0, (void *)0, (void *)0};

void	ft_init_malloc(void)
{
	TINY_HEAP_SIZE = getpagesize() * 512;
	SMALL_HEAP_SIZE = getpagesize() * 2048;
	TINY_HEAP = mmap(0, TINY_HEAP_SIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	SMALL_HEAP = mmap(0, SMALL_HEAP_SIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	((int *)TINY_HEAP)[0] = TINY_HEAP_SIZE;
	((int *)SMALL_HEAP)[0] = SMALL_HEAP_SIZE;
}

void	*ft_malloc(size_t size)
{
	size_t	alloc_size;

	if (TINY_HEAP == NULL)
		ft_init_malloc();
	if (size == 0)
		return (NULL);
	alloc_size = ALLOC_MIN;
	size += ALLOC_MIN;
	while (alloc_size < size)
		alloc_size <<= 1;
	return ((void *)ft_find_block(alloc_size));
}
