/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 05:40:14 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:13:09 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>
#include <ft_string.h>

int		ft_insert_string(char **str, int beg, int end, char *insert)
{
	char		*res;
	size_t		begsize;
	size_t		ins_size;

	begsize = ft_strlen(*str) - (end - beg + 1);
	ins_size = ft_strlen(insert);
	if (!(res = ft_strnew(sizeof(*res) * (begsize + ins_size + 10))))
		return (-1);
	ft_strncpy(res, *str, beg);
	ft_strcpy(res + beg, insert);
	ft_strcpy(res + beg + ins_size, *str + end + 1);
	free(*str);
	*str = res;
	return (0);
}

int		ft_str_replace(char **str, char *search, char *replace)
{
	char		*tmp;

	while ((tmp = ft_strstr(*str, search)))
		if (ft_insert_string(str, tmp - *str,
					tmp - *str + ft_strlen(search) - 1, replace) == -1)
			return (-1);
	return (0);
}
