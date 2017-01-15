/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:55:50 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:14:16 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(s) + 1));
	i = 0;
	if (new_str)
	{
		while (s[i])
		{
			new_str[i] = (*f)(i, s[i]);
			++i;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
