/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:44:27 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 09:09:13 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

int		add_string_to_buffer(t_arg *arg, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (arg->curs == PTF_BUFF_SIZE)
		{
			write(arg->fd, arg->buffer, PTF_BUFF_SIZE);
			arg->curs = 0;
		}
		arg->buffer[arg->curs] = str[i];
		++i;
		++arg->curs;
		if (arg->curs && arg->buffer[arg->curs - 1] == '\n')
		{
			write(arg->fd, arg->buffer, arg->curs);
			arg->curs = 0;
		}
	}
	arg->ret += i;
	return (i);
}

int		add_char_to_buffer(t_arg *arg, char c)
{
	++arg->ret;
	if (arg->curs == PTF_BUFF_SIZE)
	{
		write(arg->fd, arg->buffer, PTF_BUFF_SIZE);
		arg->curs = 0;
	}
	arg->buffer[arg->curs] = c;
	++arg->curs;
	if (arg->curs && arg->buffer[arg->curs - 1] == '\n')
	{
		write(arg->fd, arg->buffer, arg->curs);
		arg->curs = 0;
	}
	return (1);
}

int		add_int_to_buffer(t_arg *arg, intmax_t n, int base, int maj)
{
	char	*tmp;
	int		res;

	tmp = ft_itoa(n, base, maj);
	res = ft_strlen(tmp);
	add_string_to_buffer(arg, tmp);
	free(tmp);
	return (res);
}

int		add_uint_to_buffer(t_arg *arg, uintmax_t n, int base, int maj)
{
	char	*tmp;
	int		res;

	tmp = ft_itoa_u(n, base, maj);
	add_string_to_buffer(arg, tmp);
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
