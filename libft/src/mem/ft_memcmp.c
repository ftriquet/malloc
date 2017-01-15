/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:51 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:16:51 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i == n)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
