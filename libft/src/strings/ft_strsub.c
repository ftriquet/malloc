/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:33:40 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:15:53 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring)
	{
		while (i < len)
		{
			substring[i] = s[start + i];
			++i;
		}
		substring[i] = 0;
	}
	return (substring);
}
