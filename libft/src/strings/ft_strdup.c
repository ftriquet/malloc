/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:57 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:26:16 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new)
		ft_strcpy(new, s);
	return (new);
}
