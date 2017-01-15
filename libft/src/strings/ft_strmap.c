/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:33:14 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:16:16 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new_str = (char*)malloc(sizeof(*new_str) * (ft_strlen(s) + 1));
	if (new_str)
	{
		while (s[i])
		{
			new_str[i] = (*f)(s[i]);
			++i;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
