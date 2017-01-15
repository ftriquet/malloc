/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:13:25 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:16:59 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_mem.h>

void	*ft_memdup(void *ptr, size_t size)
{
	void	*ret;

	if (!ptr || !(ret = malloc(size)))
		return (NULL);
	ft_memmove(ret, ptr, size);
	return (ret);
}
