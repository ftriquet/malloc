#include <stdio.h>
#include <malloc.h>
void	dump_tiny_heap(void)
{
	int		*ptr;

	puts("+++++MEMORY DUMP TINY HEAP+++++");
	ptr = (int *)TINY_HEAP;
	while ((void *)ptr < TINY_HEAP + TINY_HEAP_SIZE)
	{
		if (ptr[1] == 1)
			printf("[%p] :: size: %d, allocated\n", ptr, ptr[0]);
		else
			printf("[%p] :: size: %d, free\n", ptr, ptr[0]);
		ptr += ptr[0] / 4;
	}
	puts("+++++++++++++++++++++++++++++++");
}

void	dump_small_heap(void)
{
	int		*ptr;

	puts("+++++MEMORY DUMP SMALL HEAP+++++");
	ptr = (int *)TINY_HEAP;
	while ((void *)ptr < SMALL_HEAP + SMALL_HEAP_SIZE)
	{
		if (ptr[1] == 1)
			printf("[%p] :: size: %d, allocated\n", ptr, ptr[0]);
		else
			printf("[%p] :: size: %d, free\n", ptr, ptr[0]);
		ptr += ptr[0] / 4;
	}
	puts("++++++++++++++++++++++++++++++++");
}
