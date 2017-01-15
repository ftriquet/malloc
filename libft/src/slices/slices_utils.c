/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:02:03 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/31 15:11:04 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slices.h>
#include <ft_mem.h>
#include <libft.h>
#include <stdlib.h>

void		*ft_slice_get(t_slice *v, int i)
{
	return (v->data[i]);
}

t_slice		*ft_slice_slice(t_slice *v, int beg, int end,
		void *(*copy)(void *))
{
	t_slice		*slice;
	int			i;

	if (end == -1)
		end = v->size;
	if (beg == -1)
		beg = 0;
	if ((end > 0 && (size_t)end > v->size) || beg > end)
		return (NULL);
	if (!(slice = ft_new_slice(end - beg)))
		return (NULL);
	i = beg - 1;
	while (++i < end)
		ft_slice_append(slice, (*copy)(ft_slice_get(v, i)));
	return (slice);
}

t_slice		*ft_slice_dup(t_slice *v, void *(cp)(void *))
{
	return (ft_slice_slice(v, -1, -1, cp));
}

int			ft_slice_put(t_slice *v, void *data, size_t i)
{
	if (i == v->size)
		return (ft_slice_append(v, data));
	v->data[i] = data;
	return (SUCCESS);
}

void		ft_slice_delete(t_slice **v, void (del)(void *))
{
	size_t		i;

	i = 0;
	if (*v == NULL)
		return ;
	while (i < (*v)->size)
	{
		(*del)((*v)->data[i]);
		++i;
	}
	free((*v)->data);
	free(*v);
	*v = NULL;
}
