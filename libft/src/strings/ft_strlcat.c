/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:05:21 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:14:08 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlcat(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (n <= dest_size)
		return (n + src_size);
	while (dest_size + i < n - 1 && src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size + i < n)
		dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
