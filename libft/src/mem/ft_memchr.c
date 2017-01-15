/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:02:49 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:16:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (ptr[i] == cc)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
