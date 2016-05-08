#ifndef MALLOC_H

# include <string.h>

# define MALLOC_H
# define TINY_HEAP_SIZE g_malloc.tiny_heap_size
# define TINY_HEAP g_malloc.tiny_heap
# define SMALL_HEAP g_malloc.small_heap
# define SMALL_HEAP_SIZE g_malloc.small_heap_size
# define ALLOC_MIN (sizeof(int) * 2)

typedef struct		s_malloc
{
	size_t			tiny_heap_size;
	size_t			small_heap_size;
	void			*tiny_heap;
	void			*small_heap;
}					t_malloc;

typedef enum		e_alloc_type
{
	TINY,
	SMALL,
	LARGE,
	NONE
}					t_alloc_type;

extern t_malloc		g_malloc;

int					ft_is_power_of_two(size_t nb);
int					ft_is_valid_addr(void *addr);

/**** TODO ****/
size_t				ft_get_alloc_size(void *addr);
int					ft_is_large_alloc(void *addr);
/**** TODO ****/

void				ft_merge_blocks(t_alloc_type type);
void				ft_merge_heap(int *ptr, void *heap,
		size_t size, size_t heap_size)



/*
int					*ft_get_block(int *current_block, size_t size);
void				*ft_malloc(size_t size);
void				ft_free(void *addr);
void				dump_memory(void);
void				ft_merge_blocks(void);
void				ft_merge_block(int *begin, size_t size);
*/

#endif
