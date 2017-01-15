/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:43:32 by ftriquet          #+#    #+#             */
/*   Updated: 2016/04/26 14:58:11 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

intmax_t	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	intmax_t	result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1 * (str[i] == '-') + 1 * (str[i] == '+');
		++i;
	}
	else
		sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (sign * result);
}
