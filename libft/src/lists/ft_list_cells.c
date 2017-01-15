/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cells.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 02:32:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/05/07 11:43:31 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <libft.h>
#include <stdlib.h>

t_list_cell		*ft_new_list_cell(void *data, t_list_cell *prev,
		t_list_cell *next)
{
	t_list_cell	*new_cell;

	if (!(new_cell = (t_list_cell *)malloc(sizeof(*new_cell))))
		return (NULL);
	if (data)
		new_cell->data = data;
	else
		new_cell->data = NULL;
	new_cell->next = next;
	new_cell->prev = prev;
	return (new_cell);
}
