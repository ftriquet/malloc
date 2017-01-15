/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:04:10 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 08:04:11 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_color(t_arg *arg, char *format)
{
	flush_buffer(arg);
	if (ft_strnequ("{red}", format, 5))
		ft_putstr(RED);
	else if (ft_strnequ("{blue}", format, 6))
		ft_putstr(BLUE);
	else if (ft_strnequ("{green}", format, 7))
		ft_putstr(GREEN);
	else if (ft_strnequ("{yellow}", format, 8))
		ft_putstr(YELLOW);
	else if (ft_strnequ("{cyan}", format, 6))
		ft_putstr(CYAN);
	else if (ft_strnequ("{eoc}", format, 5))
		ft_putstr(EOC);
	else if (ft_strnequ("{magenta}", format, 9))
		ft_putstr(MAGENTA);
	else
		return (0);
	return (1);
}

int		handle_color(t_arg *arg, char *format, int *i)
{
	if (is_color(arg, format + *i))
	{
		flush_buffer(arg);
		while (format[*i] != '}')
			(*i)++;
		(*i)++;
		return (0);
	}
	return (-1);
}
