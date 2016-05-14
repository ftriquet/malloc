#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void)
{
	struct rusage	usage;
	long			save_pages;
	getrusage(RUSAGE_SELF, &usage);
	save_pages = usage.ru_minflt;

	srand(time(NULL));
	void	*ptr[150];
	void	*ptr2;
	(void)ptr;
	(void)ptr2;

	/*
	for (int i = 0; i < 150; i++)
	{
		int rd = rand() % 1016;
		printf("Allocating %d\n", rd);
		ptr[i] = ft_malloc(rd); //should allocate 1024
		printf("%p\n", ptr[i]);
		if (ptr[i] == NULL)
			break ;
	}
	dump_memory();
	for (int i = 0; i < 150; i++)
	{
		ft_free(ptr[i]);
	}
	dump_memory();
	ft_merge_blocks();
	puts("MERGING");
	dump_memory();
	*/


	   (void)ptr;
	   puts("Allocating 500");
	   ptr2 = malloc(500);
	   printf("%p\n", ptr2);
	   puts("Allocating 1000");
	   ptr2 = malloc(1000);
	   printf("%p\n", ptr2);
	   puts("Allocating 10");
	   ptr2 = malloc(10);
	   printf("%p\n", ptr2);
	   puts("Allocating 2");
	   ptr2 = malloc(2);
	   printf("%p\n", ptr2);
	   puts("Allocating 10000");
	   ptr2 = malloc(10000);
	   printf("%p\n", ptr2);
	   puts("Free 10000");
	   free(ptr2);
	   printf("%p\n", ptr2);


	/*
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
	   */

	getrusage(RUSAGE_SELF, &usage);
	printf("RECLAIMED: %ld\n", usage.ru_minflt - save_pages - 1);
	printf("PAGE SIZE: %d\n", getpagesize());
}
