/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:28:49 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:14:30 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ft_string.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}
