/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:32:33 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 08:41:02 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	print_spaces(t_arg *arg, intmax_t n)
{
	int	size;
	int	len;
	int	print;

	size = 0;
	len = nbr_len(n, 10);
	if (arg->f_zero && !arg->f_minus && !arg->f_prec)
		size = arg->v_len;
	if (arg->f_prec && arg->v_prec)
		size = arg->v_prec;
	print = (size > len ? size : len);
	if ((arg->f_plus) && n >= 0)
		print++;
	if (n < 0 && arg->v_prec + 1 > len)
		print++;
	if ((n == 0 && arg->f_prec && arg->v_prec == 0))
		print--;
	while (!arg->f_minus && arg->v_len >= ++print)
		arg->nb_char += add_char_to_buffer(arg, ' ');
}

static void	print_prec(t_arg *arg, intmax_t n)
{
	int		size;
	int		len;

	size = 0;
	len = nbr_len(n, 10);
	if (n < 0)
	{
		if (arg->v_prec)
			arg->v_prec++;
		arg->nb_char += add_char_to_buffer(arg, '-');
	}
	else if (arg->f_plus)
		arg->nb_char += add_char_to_buffer(arg, '+');
	if (arg->f_zero && !arg->f_minus && !arg->f_prec)
		size = (arg->f_space) ? arg->v_len - 1 : arg->v_len;
	else if (arg->f_prec && arg->v_prec)
		size = arg->v_prec;
	if (arg->f_plus && n >= 0 && !arg->f_prec)
		size--;
	while (size > len)
	{
		arg->nb_char += add_char_to_buffer(arg, '0');
		size--;
	}
}

static void	print_d(t_arg *arg, intmax_t n)
{
	if (!arg->f_plus && arg->f_space && n >= 0 && !arg->v_prec)
		arg->nb_char += add_char_to_buffer(arg, ' ');
	print_spaces(arg, n);
	print_prec(arg, n);
	if (n < 0)
		arg->nb_char += add_uint_to_buffer(arg, -n, 10, 0);
	else if (!(arg->f_prec && !arg->v_prec && n == 0))
		arg->nb_char += add_uint_to_buffer(arg, n, 10, 0);
	make_padding(arg);
}

void		handle_d(t_arg *arg, va_list ap)
{
	if (arg->mod == NULL && arg->conv != 'D')
		print_d(arg, (int)va_arg(ap, int));
	else if (arg->conv == 'D' || ft_strcmp(arg->mod, "l") == 0)
		print_d(arg, va_arg(ap, long int));
	else if (ft_strcmp(arg->mod, "ll") == 0)
		print_d(arg, va_arg(ap, long long int));
	else if (ft_strcmp(arg->mod, "h") == 0)
		print_d(arg, (short)va_arg(ap, int));
	else if (ft_strcmp(arg->mod, "hh") == 0)
		print_d(arg, (char)va_arg(ap, int));
	else if (ft_strcmp(arg->mod, "j") == 0)
		print_d(arg, va_arg(ap, long));
	else if (ft_strcmp(arg->mod, "z") == 0)
		print_d(arg, va_arg(ap, size_t));
}
