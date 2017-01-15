/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:44:47 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:14:05 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join)
	{
		ft_strcpy(join, s1);
		ft_strcat(join, s2);
	}
	return (join);
}
