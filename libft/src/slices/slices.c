/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:28:26 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/31 15:11:36 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slices.h>
#include <ft_mem.h>
#include <stdlib.h>
#include <libft.h>

t_slice		*ft_new_slice(size_t cap)
{
	t_slice	*vec;

	if (cap == 0)
		cap = 10;
	if (!(vec = (t_slice *)ft_memalloc(sizeof(t_slice))))
		return (NULL);
	if (!(vec->data = (void **)ft_memalloc(sizeof(void *) * (cap))))
	{
		free(vec);
		return (NULL);
	}
	vec->size = 0;
	vec->cap = cap;
	return (vec);
}

int			ft_slice_realloc_buffer(t_slice *s)
{
	void	**new_data;

	if (!(new_data = (void **)ft_memalloc(sizeof(void *) * (s->size * 2))))
		return (FAILURE);
	ft_memmove(new_data, s->data, sizeof(void *) * s->size);
	free(s->data);
	s->data = new_data;
	s->cap *= 2;
	return (SUCCESS);
}

int			ft_slice_append(t_slice *s, void *data)
{
	if (s->size == s->cap)
	{
		if (ft_slice_realloc_buffer(s) == FAILURE)
			return (FAILURE);
	}
	s->data[s->size] = data;
	++s->size;
	return (SUCCESS);
}

int			ft_slice_add(t_slice *s, void *data, size_t i)
{
	size_t		j;

	if (s->size == s->cap)
	{
		if (ft_slice_realloc_buffer(s) == FAILURE)
			return (FAILURE);
	}
	j = s->size;
	while (j > i)
	{
		s->data[j] = s->data[j - 1];
		--j;
	}
	++s->size;
	s->data[i] = data;
	return (SUCCESS);
}

int			ft_slice_push(t_slice *s, void *data)
{
	return (ft_slice_add(s, data, 0));
}
