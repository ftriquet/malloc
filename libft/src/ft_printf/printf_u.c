/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:32:22 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 11:33:39 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static void	print_prefix(t_arg *arg, uintmax_t n)
{
	if ((!arg->f_hashtag && arg->conv != 'p') ||
			(!n && arg->conv != 'o' && arg->conv != 'p' &&
			arg->conv != 'O') || (arg->conv != 'o' && arg->conv != 'O' &&
				arg->conv != 'x' && arg->conv != 'X' && arg->conv != 'p'))
		return ;
	if ((arg->conv == 'o' || arg->conv == 'O') && n == 0 && !arg->f_prec)
		return ;
	add_char_to_buffer(arg, '0');
	arg->nb_char++;
	if (arg->conv == 'x' || arg->conv == 'p')
	{
		add_char_to_buffer(arg, 'x');
		arg->nb_char++;
	}
	if (arg->conv == 'X')
	{
		add_char_to_buffer(arg, 'X');
		arg->nb_char++;
	}
}

static void	print_spaces_u(t_arg *arg, uintmax_t n, int base)
{
	int		size;
	int		len;
	int		print;

	size = 0;
	len = nbr_len_u(n, base);
	if (arg->f_zero && !arg->f_minus && !arg->f_prec)
		size = arg->v_len;
	if (arg->f_prec && arg->v_prec)
		size = arg->v_prec;
	print = (size > len ? size : len);
	if (arg->f_hashtag || arg->conv == 'p')
		print += 1 + (arg->conv != 'o');
	if (arg->f_plus)
		print++;
	if ((n == 0 && arg->f_prec && arg->v_prec == 0))
		print--;
	while (!arg->f_minus && arg->v_len >= ++print)
		arg->nb_char += add_char_to_buffer(arg, ' ');
}

static void	print_prec_u(t_arg *arg, uintmax_t n, int base)
{
	int		s;
	int		l;

	s = 0;
	l = nbr_len_u(n, base);
	if (arg->f_zero && !arg->f_prec && !arg->f_minus)
		s = arg->v_len;
	else if (arg->v_prec)
		s = arg->v_prec;
	print_prefix(arg, n);
	if (!arg->f_prec && (arg->f_hashtag)
			&& (arg->conv == 'x' ||
				arg->conv == 'X' || arg->conv == 'o' || arg->conv == 'O'))
		s -= (1 + (arg->conv == 'x' || arg->conv == 'X' || arg->conv == 'p'));
	if (!arg->f_prec && arg->conv == 'p')
		s -= 2;
	else if ((arg->conv == 'o' || arg->conv == 'O') && arg->f_hashtag)
		s--;
	while (s > l)
	{
		arg->nb_char += add_char_to_buffer(arg, '0');
		s--;
	}
}

static void	print_u(t_arg *arg, uintmax_t n, int base)
{
	int		length;

	print_spaces_u(arg, n, base);
	print_prec_u(arg, n, base);
	length = nbr_len_u(n, base) + arg->nb_char;
	if (arg->f_space || arg->f_plus)
		length--;
	if (!(arg->f_prec && arg->v_prec == 0 && n == 0))
		arg->nb_char += add_uint_to_buffer(arg, n, base, arg->conv == 'X');
	make_padding(arg);
}

void		handle_uxo(t_arg *arg, va_list ap)
{
	int	base;

	base = 8;
	if (arg->conv == 'u' || arg->conv == 'U')
		base = 10;
	else if (arg->conv == 'x' || arg->conv == 'X')
		base = 16;
	if (arg->conv == 'p')
		print_u(arg, va_arg(ap, unsigned long), 16);
	else if (arg->conv == 'O')
		print_u(arg, va_arg(ap, unsigned long), 8);
	else if (arg->mod == NULL && arg->conv != 'U')
		print_u(arg, va_arg(ap, unsigned int), base);
	else if (arg->conv == 'U' || ft_strcmp(arg->mod, "l") == 0)
		print_u(arg, va_arg(ap, unsigned long), base);
	else if (ft_strcmp(arg->mod, "ll") == 0)
		print_u(arg, va_arg(ap, unsigned long long int), base);
	else if (ft_strcmp(arg->mod, "h") == 0)
		print_u(arg, (unsigned short)va_arg(ap, int), base);
	else if (ft_strcmp(arg->mod, "hh") == 0)
		print_u(arg, (unsigned char)va_arg(ap, int), base);
	else if (ft_strcmp(arg->mod, "j") == 0)
		print_u(arg, va_arg(ap, uintmax_t), base);
	else if (ft_strcmp(arg->mod, "z") == 0)
		print_u(arg, va_arg(ap, size_t), base);
}
