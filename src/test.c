#include <stdio.h>
#include <malloc.h>

int main(void)
{
	void	*ptr[5];

	/*
	   for (int i = 0; i < 100; i++)
	   {
	   ptr = ft_malloc(50); //should allocate 64
	   printf("%p\n", ptr);
	   dump_memory();
	   }
	   */
	/*
	   (void)ptr;
	   puts("Allocating 500");
	   ptr = ft_malloc(500);
	   dump_memory();
	   puts("Allocating 1000");
	   ptr = ft_malloc(1000);
	   dump_memory();
	   puts("Allocating 10");
	   ptr = ft_malloc(10);
	   dump_memory();
	   puts("Allocating 2");
	   ptr = ft_malloc(2);
	   dump_memory();
	   puts("Allocating 10000");
	   ptr = ft_malloc(10000);
	   dump_memory();
	   */
	ptr[0] = ft_malloc(12);
	puts("allocating 12");
	dump_memory();
	ptr[1] = ft_malloc(45);
	puts("allocating 45");
	dump_memory();
	ptr[2] = ft_malloc(10);
	puts("allocating 10");
	dump_memory();
	ptr[3] = ft_malloc(1000);
	puts("allocating 1000");
	dump_memory();
	ptr[4] = ft_malloc(10000);
	puts("allocating 10000");
	dump_memory();

	puts("===================");
	puts("FREE AND MERGE");
	puts("===================");

	puts("free 12");
	ft_free(ptr[0]);
	ft_merge_blocks();
	dump_memory();
	puts("free 45");
	ft_free(ptr[1]);
	ft_merge_blocks();
	dump_memory();
	puts("free 10");
	ft_free(ptr[2]);
	ft_merge_blocks();
	dump_memory();
	puts("free 1000");
	ft_free(ptr[3]);
	ft_merge_blocks();
	dump_memory();
	puts("free 10000");
	ft_free(ptr[4]);
	ft_merge_blocks();
	dump_memory();
}
