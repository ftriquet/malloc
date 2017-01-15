/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:34:34 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 11:13:19 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		get_nb_octs(unsigned int c)
{
	int		i;

	i = 0;
	while (c)
	{
		i++;
		c = c >> 1;
	}
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

int		putnstr(t_arg *arg, char *s, int n)
{
	int		i;

	i = 0;
	while (s[i] && i < n)
	{
		add_char_to_buffer(arg, s[i]);
		++i;
	}
	return (i);
}

int		putnwchar(t_arg *arg, wchar_t *ch, int n)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = arg->nb_char;
	if (arg->f_prec && arg->v_prec == 1)
		n++;
	while (ch[i] && i < n)
	{
		if (arg->nb_char - tmp >= arg->v_prec - 1 &&
				arg->f_prec && arg->v_prec != 1)
			break ;
		put_wchar(arg, (unsigned int)ch[i]);
		++i;
	}
	return (i);
}
