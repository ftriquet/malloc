/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:36:08 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 11:13:01 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_s(t_arg *arg, va_list ap)
{
	print_s(arg, va_arg(ap, void *));
	return (1);
}

static int	wcharlen(wchar_t *s)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s && s[i])
	{
		i++;
		size += get_nb_octs(s[i]);
	}
	return (size + 2);
}

static void	print_s_noprec(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->v_len)
	{
		if (!arg->f_zero)
			arg->nb_char += add_char_to_buffer(arg, ' ');
		else
			arg->nb_char += add_char_to_buffer(arg, '0');
		i++;
	}
}

static void	useless_func(t_arg *arg, void **s, int size, int opt)
{
	if (opt)
	{
		if (arg->conv == 's')
			arg->nb_char += putnstr(arg, *s, size);
		else
			putnwchar(arg, *((wchar_t **)s), size);
		make_padding(arg);
	}
	else
	{
		if (arg->mod && arg->mod[0] == 'l')
			arg->conv = 'S';
		if (*((char **)s) == NULL)
		{
			arg->conv = 's';
			*s = "(null)";
		}
	}
}

void		print_s(t_arg *arg, void *s)
{
	int		size;
	int		len;
	int		print;

	len = INT_MAX;
	if (arg->f_prec && arg->v_prec == 0)
		return (print_s_noprec(arg));
	useless_func(arg, (&s), 0, 0);
	len = arg->conv == 's' ? (int)ft_strlen(s) : wcharlen(s);
	size = arg->v_prec && arg->v_prec < len ? arg->v_prec - (arg->conv == 'S') :
		(int)ft_strlen(s);
	if (!arg->f_prec && (arg->conv == 'S'))
		size = wcharlen(s);
	print = size;
	if (arg->conv == 'S' && arg->v_prec == 1)
		++print;
	while (!arg->f_minus && arg->v_len >= ++print)
		arg->nb_char += arg->f_zero ? add_char_to_buffer(arg, '0') :
			add_char_to_buffer(arg, ' ');
	if (arg->conv == 'S' && arg->f_prec && arg->v_prec >= arg->v_len)
		useless_func(arg, (&s), arg->v_prec, 1);
	else
		useless_func(arg, (&s), size, 1);
}
