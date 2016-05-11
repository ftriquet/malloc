#ifndef MALLOC_H

# include <string.h>
# include <unistd.h>

# define MALLOC_H
# define TINY_HEAP g_malloc.tiny_heap
# define SMALL_HEAP g_malloc.small_heap
# define TINY_HEAP_SIZE (getpagesize() * 512)
# define SMALL_HEAP_SIZE (getpagesize() * 64)
# define TINY_ALLOC_LIMIT (1024)
# define SMALL_ALLOC_LIMIT ((1024 * 16))
# define ALLOC_MIN (sizeof(int) * 2)
# define ALIGN_SIZE(x) (((((x) - 1) >> 3) << 3) + 8)
# define BLOCK_SIZE (sizeof(t_ui) * 2 + sizeof(t_memblock *))


typedef unsigned int	t_ui;

typedef struct			s_memblock
{
	t_ui				size;
	t_ui				free;
	struct s_memblock	*next;
	char				data[1];
}						t_memblock;

extern t_malloc			g_malloc;

typedef struct			s_malloc
{
	/* size_t				tiny_heap_size; */
	/* size_t				small_heap_size; */
	void				*tiny_heap;
	void				*small_heap;
}						t_malloc;

typedef enum			e_alloc_type
{
	TINY,
	SMALL,
	LARGE,
	NONE
}						t_alloc_type;


t_memblock	*ft_find_block(t_memblock **last, size_t size);
t_memblock	*ft_extend_heap(t_memblock *last, size_t size);
void		ft_split_block(t_memblock *block, size_t size);
void		*ft_large_alloc(size_t size);
void		*ft_alloc(t_memblock *last, size_t size, t_alloc_type type);
void		*ft_malloc(size_t size);
int			ft_init_malloc(void);

#endif
