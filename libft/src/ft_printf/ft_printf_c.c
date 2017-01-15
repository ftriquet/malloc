/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:38:57 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 09:36:04 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	handle_c(t_arg *arg, va_list ap)
{
	int		i;

	i = arg->v_len;
	while (i > arg->v_prec && !arg->f_minus && i-- > 1)
		arg->nb_char += arg->f_zero ? add_char_to_buffer(arg, '0') :
			add_char_to_buffer(arg, ' ');
	while (!arg->f_minus && i-- > 1)
		arg->nb_char += add_char_to_buffer(arg, '0');
	if (arg->mod == NULL && arg->conv == 'c')
		arg->nb_char += add_char_to_buffer(arg, (char)va_arg(ap, int));
	else if ((arg->mod && ft_strcmp(arg->mod, "l") == 0) || arg->conv == 'C')
		put_wchar(arg, (unsigned int)va_arg(ap, wchar_t));
	make_padding(arg);
}

void	make_padding(t_arg *arg)
{
	int size;

	size = 0;
	if (arg->f_minus)
		size = arg->v_len;
	while (size > arg->nb_char)
	{
		add_char_to_buffer(arg, ' ');
		size--;
	}
}
