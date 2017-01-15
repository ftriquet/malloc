/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:10:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/30 17:13:48 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_list.h>
#include <stdlib.h>

void			*ft_list_remove_back(t_list *list)
{
	t_list_cell	*tmp;
	void		*res;

	res = NULL;
	if (list->size == 0)
		return (res);
	tmp = list->last;
	list->last = list->last->prev;
	if (list->last)
		list->last->next = NULL;
	res = tmp->data;
	free(tmp);
	if (list->last == NULL)
		list->first = NULL;
	--list->size;
	return (res);
}

void			*ft_list_remove_front(t_list *list)
{
	t_list_cell	*tmp;
	void		*res;

	res = NULL;
	if (list->size == 0)
		return (res);
	tmp = list->first;
	list->first = list->first->next;
	if (list->first)
		list->first->prev = NULL;
	res = tmp->data;
	free(tmp);
	if (list->first == NULL)
		list->last = NULL;
	--list->size;
	return (res);
}

void			*ft_list_remove(t_list *list, void *data,
		int (*cmp)(void *, void *))
{
	t_list_cell	*it;
	t_list_cell	*tmp;
	void		*res;

	it = list->first;
	res = NULL;
	if ((*cmp)(data, it->data) == 0)
		return (ft_list_remove_front(list));
	if ((*cmp)(data, list->last->data) == 0)
		return (ft_list_remove_back(list));
	while ((tmp = it->next))
	{
		if ((*cmp)(data, it->next->data) == 0)
		{
			tmp->next->prev = it;
			it->next = tmp->next;
			--list->size;
			res = tmp->data;
			free(tmp);
			break ;
		}
		it = it->next;
	}
	return (res);
}

void			*ft_list_remove_at(t_list *list, size_t pos)
{
	t_list_cell *it;
	t_list_cell *tmp;
	void		*res;

	if (pos >= list->size)
		return (NULL);
	if (pos == 0)
		return (ft_list_remove_front(list));
	if (pos == list->size - 1)
		return (ft_list_remove_back(list));
	--list->size;
	it = list->first;
	while (--pos > 1)
		it = it->next;
	tmp = it->next;
	res = tmp->data;
	it->next = tmp->next;
	it->next->prev = it;
	free(tmp);
	return (res);
}
