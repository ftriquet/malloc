/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:18:01 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:13:54 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s2 == NULL || s1 == NULL)
		return (0);
	return (ft_strcmp(s1, s2) == 0);
}
