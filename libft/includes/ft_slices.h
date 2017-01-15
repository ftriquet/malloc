/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slices.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:28:22 by ftriquet          #+#    #+#             */
/*   Updated: 2017/01/15 12:51:22 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLICES_H
# define FT_SLICES_H
# include <string.h>

typedef struct		s_slice
{
	void			**data;
	size_t			size;
	size_t			cap;
}					t_slice;

t_slice				*ft_new_slice(size_t cap);
int					ft_slice_push(t_slice *s, void *data);
int					ft_slice_add(t_slice *s, void *data, size_t i);
int					ft_slice_append(t_slice *s, void *data);
int					ft_slice_realloc_buffer(t_slice *s);
t_slice				*ft_slice_slice(t_slice *v, int beg, int end,
		void *(*copy)(void *));
void				*ft_slice_get(t_slice *v, int i);
int					ft_slice_put(t_slice *v, void *data, size_t i);
t_slice				*ft_slice_dup(t_slice *v, void *(cp)(void *));
void				ft_slice_delete(t_slice **v, void (del)(void *));
t_slice				*ft_slice_map(t_slice *v, void *(*f)(void *));
void				ft_slice_iter(t_slice *v, void (*f)(void *));
int					ft_slice_match(t_slice *s, int (*f)(void *));
void				ft_slice_merge_sort(t_slice *slice,
		int (*cmp)(void *, void *));
void				*ft_slice_reduce(t_slice *s, void *(*f)(void *, void *),
		void *init);

#endif
