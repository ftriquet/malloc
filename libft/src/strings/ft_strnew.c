/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:12:53 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:31:41 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_mem.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str)
		ft_bzero(str, size + 1);
	return (str);
}
