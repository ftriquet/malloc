/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:07:10 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:20:36 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <ft_mem.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
