/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 05:27:28 by ftriquet          #+#    #+#             */
/*   Updated: 2016/06/01 21:34:18 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stdlib.h>

t_list			ft_list_map(t_list *list, t_list_cell *(*func)(t_list_cell *),
		void (*del_func)(void *))
{
	t_list_cell	*it;
	t_list_cell	*tmp;
	t_list		res;

	ft_list_init(&res, del_func);
	it = list->first;
	while (it)
	{
		tmp = (*func)(it);
		ft_list_add_back(list, tmp->data);
		(*del_func)(tmp->data);
		free(tmp);
	}
	return (res);
}
