/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:41:18 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:17:02 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	else if (src < dst)
	{
		i = len;
		while (i)
		{
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
