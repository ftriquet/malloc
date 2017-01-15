/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slices_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:51:49 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/31 15:10:27 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_slice_iter(t_slice *v, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < v->size)
	{
		(*f)(v->data[i]);
		++i;
	}
}

t_slice		*ft_slice_map(t_slice *v, void *(*f)(void *))
{
	t_slice		*res;
	size_t		i;

	if (!(res = ft_new_slice(v->size)))
		return (NULL);
	i = 0;
	while (i < v->size)
	{
		ft_slice_append(res, (*f)(v->data[i]));
		++i;
	}
	return (res);
}

int			ft_slice_match(t_slice *s, int (*f)(void *))
{
	size_t		i;

	i = 0;
	while (i < s->size)
	{
		if ((*f)(s->data[i]))
			return (1);
		++i;
	}
	return (0);
}
