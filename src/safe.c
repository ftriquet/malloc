#include <malloc.h>

void		*malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_malloc_locker);
	ptr = malloc_unsafe(size);
	pthread_mutex_unlock(&g_malloc_locker);
	return (ptr);

}

void		free(void *addr)
{
	pthread_mutex_lock(&g_free_locker);
	free_unsafe(addr);
	pthread_mutex_unlock(&g_free_locker);

}

void		*realloc(void *addr, size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_realloc_locker);
	ptr = realloc_unsafe(addr, size);
	pthread_mutex_unlock(&g_realloc_locker);
	return (ptr);
}
