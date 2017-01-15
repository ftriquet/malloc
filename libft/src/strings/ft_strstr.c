/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:07:15 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:15:50 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char*)s1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i + j] && s1[i + j] == s2[j])
		{
			++j;
		}
		if (!s2[j])
			return ((char*)(s1 + i));
		++i;
	}
	return (NULL);
}
