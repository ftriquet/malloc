/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:11:19 by ftriquet          #+#    #+#             */
/*   Updated: 2017/01/15 17:14:55 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_alloc_type	get_block_type(t_memblock *block)
{
	if (block->size < TINY_ALLOC_LIMIT)
		return (TINY);
	if (block->size < SMALL_ALLOC_LIMIT)
		return (SMALL);
	return (LARGE);
}

t_alloc_type	get_alloc_type(size_t size)
{
	if (size < TINY_ALLOC_LIMIT)
		return (TINY);
	if (size < SMALL_ALLOC_LIMIT)
		return (SMALL);
	return (LARGE);
}
