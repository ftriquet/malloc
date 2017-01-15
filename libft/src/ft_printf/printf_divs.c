/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_divs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:17:28 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 09:37:02 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		flush_buffer(t_arg *arg)
{
	if (arg->curs)
	{
		write(arg->fd, arg->buffer, arg->curs);
		arg->curs = 0;
	}
}

void		handle_other(t_arg *arg)
{
	char	*res;

	res = ft_strnew(2);
	res[0] = arg->conv;
	if (arg->f_prec && !arg->v_prec)
		arg->v_prec = 1;
	arg->conv = 's';
	print_s(arg, res);
	free(res);
}

int			handle_conv(t_arg *arg, va_list ap, char *format, int *i)
{
	init_arg(arg);
	*i += fill_arg(arg, format + *i);
	if (arg->conv == 'd' || arg->conv == 'D' || arg->conv == 'i')
		handle_d(arg, ap);
	else if (arg->conv == 's' || arg->conv == 'S')
		handle_s(arg, ap);
	else if (arg->conv == 'x' || arg->conv == 'X' || arg->conv == 'p' ||
			arg->conv == 'o' || arg->conv == 'u' || arg->conv == 'U' ||
			arg->conv == 'O')
		handle_uxo(arg, ap);
	else if (arg->conv == 'c' || arg->conv == 'C')
		handle_c(arg, ap);
	else
		handle_other(arg);
	free(arg->format);
	return (1);
}

void		init_printf(t_arg *arg, int fd)
{
	arg->ret = 0;
	arg->curs = 0;
	arg->err = 0;
	arg->fd = fd;
}
