/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:04:06 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 08:23:07 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

static void	handle_format(t_arg *arg, char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && format[i + 1] == '%' && (i += 2))
				add_char_to_buffer(arg, '%');
			else
				handle_conv(arg, ap, format, &i);
		}
		else if (format[i] == '{' && handle_color(arg, format, &i) == 0)
			continue ;
		else
			add_char_to_buffer(arg, format[i++]);
	}
	flush_buffer(arg);
}

int			ft_printf(char *format, ...)
{
	t_arg	arg;
	va_list	ap;

	if (!format)
		return (-1);
	init_printf(&arg, STDOUT_FILENO);
	va_start(ap, format);
	handle_format(&arg, format, ap);
	va_end(ap);
	return (arg.err == -1 ? arg.err : arg.ret);
}

int			ft_dprintf(int fd, char *format, ...)
{
	t_arg	arg;
	va_list	ap;

	if (!format)
		return (-1);
	init_printf(&arg, fd);
	va_start(ap, format);
	handle_format(&arg, format, ap);
	va_end(ap);
	return (arg.err == -1 ? arg.err : arg.ret);
}
