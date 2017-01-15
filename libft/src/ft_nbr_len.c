/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:23:46 by ftriquet          #+#    #+#             */
/*   Updated: 2016/04/25 20:47:39 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

int		nbr_len_u(uintmax_t n, int base)
{
	int		i;

	i = 1;
	while (n >= (size_t)base)
	{
		++i;
		n /= base;
	}
	return (i);
}

int		nbr_len(intmax_t nb, int base)
{
	if (nb < 0)
		return (1 + nbr_len_u(-nb, base));
	else
		return (nbr_len_u(nb, base));
}
