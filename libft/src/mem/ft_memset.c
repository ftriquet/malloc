/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:59:50 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:17:05 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	val;

	val = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = val;
		i++;
	}
	return (b);
}
