/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 02:38:58 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/30 17:13:29 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stdlib.h>
#include <libft.h>

int				ft_list_add_back(t_list *list, void *data)
{
	t_list_cell	*new_cell;

	if (!(new_cell = ft_new_list_cell(data, list->last, NULL)))
		return (-1);
	if (list->last)
		list->last->next = new_cell;
	list->last = new_cell;
	if (list->size == 0)
		list->first = new_cell;
	++list->size;
	return (list->size - 1);
}

int				ft_list_add_front(t_list *list, void *data)
{
	t_list_cell	*new_cell;

	if (!(new_cell = ft_new_list_cell(data, NULL, list->first)))
		return (-1);
	list->first = new_cell;
	if (list->size == 0)
		list->last = new_cell;
	else if (list->size == 1)
		list->last->prev = list->first;
	else
		list->first->next->prev = list->first;
	++list->size;
	return (0);
}

int				ft_list_add_pos(t_list *list, void *data, size_t pos)
{
	t_list_cell	*it;
	t_list_cell	*new_cell;
	size_t		i;

	if (pos == 0)
		return (ft_list_add_front(list, data));
	if (pos >= list->size)
		return (ft_list_add_back(list, data));
	if (!(new_cell = ft_new_list_cell(data, NULL, NULL)))
		return (-1);
	++list->size;
	it = list->first;
	i = 1;
	while (i++ < pos)
		it = it->next;
	new_cell->next = it->next;
	new_cell->prev = it;
	it->next = new_cell;
	return (pos);
}

int				ft_list_add_sort(t_list *list, void *data,
		int (*cmp)(void *, void *))
{
	t_list_cell	*it;
	t_list_cell	*new_cell;
	size_t		pos;

	pos = 0;
	it = list->first;
	if (list->size == 0 || (*cmp)(list->first->data, data) > 0)
		return (ft_list_add_front(list, data));
	while (it->next && ++pos &&
			(*cmp)(it->next->data, data) < 0)
		it = it->next;
	if (!(new_cell =
				ft_new_list_cell(data, it, it->next)))
		return (-1);
	++list->size;
	it->next = new_cell;
	if (new_cell->next == NULL)
		list->last = new_cell;
	else
		new_cell->next->prev = new_cell;
	return (pos - 1);
}
