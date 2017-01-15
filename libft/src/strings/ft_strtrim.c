/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:52:05 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 17:56:30 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strtrim(const char *s)
{
	char	*trim;
	size_t	beg;
	size_t	end;

	trim = NULL;
	if (s)
	{
		beg = 0;
		end = ft_strlen(s) - 1;
		while (s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n')
			beg++;
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		if (s[beg])
		{
			trim = ft_strnew(end - beg + 2);
			if (trim)
				ft_strncpy(trim, s + beg, end - beg + 1);
		}
		else
			return (ft_strnew(1));
	}
	return (trim);
}
