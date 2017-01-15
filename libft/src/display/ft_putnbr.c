/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:42:54 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:24:37 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(intmax_t nb, int base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		return (ft_putunbr(-nb, base));
	}
	if (nb > 9)
		ft_putnbr(nb / base, base);
	ft_putchar(digit(nb % base, 1));
}

void	ft_putunbr(uintmax_t nb, int base)
{
	if (nb > 9)
		ft_putnbr(nb / base, base);
	ft_putchar(digit(nb % base, 1));
}
