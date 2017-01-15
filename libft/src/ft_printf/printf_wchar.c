/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:28:33 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 10:02:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void			put_wchar(t_arg *arg, unsigned int c)
{
	int		l;

	flush_buffer(arg);
	l = get_nb_octs(c);
	if (l == 1)
		print_wchar1(arg, c);
	else if (l == 2)
		print_wchar2(arg, c);
	else if (l == 3)
		print_wchar3(arg, c);
	else
		print_wchar4(arg, c);
	arg->ret += l;
	if (arg->conv == 'c' || arg->conv == 'C')
		make_padding(arg);
}

void			print_wchar1(t_arg *arg, unsigned int c)
{
	unsigned char ch;

	if (arg)
		arg->nb_char++;
	ch = (unsigned char)c;
	write(arg->fd, &ch, 1);
}

void			print_wchar2(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;

	if (arg)
		arg->nb_char += 2;
	mask = 49280;
	mask |= ((c << 26) >> 26);
	mask |= (((c << 21) >> 27) << 8);
	w = ((unsigned char *)&mask)[1];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(arg->fd, &w, 1);
}

void			print_wchar3(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;
	unsigned int	oct;

	if (arg)
		arg->nb_char += 3;
	mask = 0b111000001000000010000000;
	oct = (unsigned char)((c << 26) >> 26);
	mask |= oct;
	oct = (((unsigned char)((c << 24) >> 30)) << 8);
	mask |= oct;
	oct = ((unsigned int)(((c << 20) >> 26))) << 8;
	mask |= oct;
	oct = (unsigned int)(((c >> 12) << 16));
	mask |= oct;
	w = ((unsigned char *)&mask)[2];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[1];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(arg->fd, &w, 1);
}

void			print_wchar4(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;
	unsigned int	oct;

	if (arg)
		arg->nb_char += 4;
	mask = 0b11110000100000001000000010000000;
	oct = (c << 26) >> 26;
	mask |= oct;
	oct = ((c << 20) >> 26) << 8;
	mask |= oct;
	oct = ((c << 14) >> 26) << 16;
	mask |= oct;
	oct = ((c << 10) >> 26) << 24;
	mask |= oct;
	w = ((unsigned char *)&mask)[3];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[2];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[1];
	write(arg->fd, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(arg->fd, &w, 1);
}
