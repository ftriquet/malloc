/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:34:58 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/28 18:26:59 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		digit(int nb, int maj)
{
	if (nb < 10)
		return ('0' + nb);
	if (maj)
		return ('A' + nb % 10);
	return ('a' + nb % 10);
}

char		*ft_itoa_u(uintmax_t n, int base, int maj)
{
	char	*res;
	int		size;

	size = nbr_len_u(n, base);
	if (!(res = malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = 0;
	while (size-- >= 1)
	{
		res[size] = digit(n % base, maj);
		n /= base;
	}
	return (res);
}

char		*ft_itoa(intmax_t n, int base, int maj)
{
	char	*res;
	char	*tmp;

	if (n < 0)
	{
		tmp = ft_itoa_u(-n, base, maj);
		res = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
		res = ft_itoa_u(n, base, maj);
	return (res);
}
