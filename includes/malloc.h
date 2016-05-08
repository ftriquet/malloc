#ifndef MALLOC_H
# define MALLOC_H
# define HEAP_SIZE 1024 * 1024
# define ALLOC_MIN (sizeof(int) * 2)

int		*ft_get_block(int *current_block, size_t size);
void	*ft_malloc(size_t size);
void	ft_free(void *addr);
void	dump_memory(void);
void	ft_merge_blocks(void);
void	ft_merge_block(int *begin, size_t size);

#endif
