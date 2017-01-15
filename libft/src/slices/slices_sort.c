/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slices_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 00:20:44 by ftriquet          #+#    #+#             */
/*   Updated: 2016/06/03 00:21:19 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	*cp(void *elem)
{
	return (elem);
}

static void	do_nothing(void *elem)
{
	(void)elem;
}

static void	ft_merge_slices(t_slice *main, t_slice *left, t_slice *right,
		int (*cmp)(void *, void *))
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < left->size && j < right->size)
	{
		if ((*cmp)(ft_slice_get(left, i), ft_slice_get(right, j)) < 0)
			ft_slice_put(main, ft_slice_get(left, i++), k);
		else
			ft_slice_put(main, ft_slice_get(right, j++), k);
		++k;
	}
	while (i < left->size)
		ft_slice_put(main, ft_slice_get(left, i++), k++);
	while (j < right->size)
		ft_slice_put(main, ft_slice_get(right, j++), k++);
}

void		ft_slice_merge_sort(t_slice *slice, int (*cmp)(void *, void *))
{
	t_slice			*left;
	t_slice			*right;

	if (slice->size <= 1)
		return ;
	left = ft_slice_slice(slice, -1, slice->size / 2, &cp);
	right = ft_slice_slice(slice, slice->size / 2, -1, &cp);
	ft_slice_merge_sort(left, cmp);
	ft_slice_merge_sort(right, cmp);
	ft_merge_slices(slice, left, right, cmp);
	ft_slice_delete(&left, &do_nothing);
	ft_slice_delete(&right, &do_nothing);
}
