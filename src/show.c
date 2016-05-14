#include <malloc.h>
#include <libft.h>

void	show_alloc_mem(void)
{
	t_memblock	*b;

	b = TINY_HEAP;
	write(1, "TINY: ", 6);
	print_memzone(b);
	b = SMALL_HEAP;
	write(1, "SMALL: ", 6);
	print_memzone(b);
	b = LARGE_HEAP;
	write(1, "LARGE: ", 6);
	print_memzone(b);
}

void	print_addr(void *addr)
{
	write(1, "0x", 2);
	ft_putnbr((int)addr, 16);
}

void	print_memzone(t_memblock *b)
{
	print_addr(b);
	write(1, "\n", 1);
	while (b)
	{
		print_addr((void *)(b->data));
		write(1, " - ", 3);
		print_addr((void *)(b->data + b->size));
		write(1, " : ", 3);
		ft_putnbr((int)(b->size), 10);
		write(1, " octets\n", 7);
		b = b->next;
	}
}
