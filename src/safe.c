#include <malloc.h>

void		*malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_locker);
	ptr = malloc_unsafe(size);
	pthread_mutex_unlock(&g_locker);
	return (ptr);

}

void		free(void *addr)
{
	pthread_mutex_lock(&g_locker);
	free_unsafe(addr);
	pthread_mutex_unlock(&g_locker);

}

void		*realloc(void *addr, size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_locker);
	ptr = realloc_unsafe(addr, size);
	pthread_mutex_unlock(&g_locker);
	return (ptr);
}
