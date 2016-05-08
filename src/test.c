#include <stdio.h>
#include <malloc.h>

int main(void)
{
	void	*ptr;

	for (int i = 0; i < 100; i++)
	{
		ptr = ft_malloc(50); //should allocate 64
		printf("%p\n", ptr);
		dump_memory();
	}
}
