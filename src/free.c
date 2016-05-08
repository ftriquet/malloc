#include <malloc.h>
#include <stdio.h>
#include <sys/mman.h>

int		ft_is_large_alloc(void *addr)
{
	// TODO
	(void)addr;
	return (1);
}

size_t	ft_get_alloc_size(void *addr)
{
	// TODO
	(void)addr;
	return (0);
}

int		ft_is_valid_addr(void *addr)
{
	if (addr >= TINY_HEAP && addr < TINY_HEAP + TINY_HEAP_SIZE &&
			ft_is_power_of_two(addr - TINY_HEAP- ALLOC_MIN))
		return (TINY);
	if (addr >= SMALL_HEAP && addr < SMALL_HEAP + SMALL_HEAP_SIZE &&
			ft_is_power_of_two(addr - SMALL_HEAP - ALLOC_MIN))
		return (SMALL);
	if (ft_is_large_alloc(addr))
		return (LARGE);
	return (NONE);
}


void	ft_free(void *addr)
{
	int				*tmp;
	t_alloc_type	type;

	type = ft_is_valid_addr(addr);
	if (type == TINY || type == SMALL)
	{
		puts("FREEEEEE");
		tmp = addr;
		tmp -= 2;
		if (tmp[1] != 1)
			return ;
		tmp[1] = 0;
		ft_merge_blocks(type);
	}
	else if (type == LARGE)
		munmap(addr, ft_get_alloc_size(addr));
}
