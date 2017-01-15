/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:28:21 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 08:28:25 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	init_arg(t_arg *arg)
{
	arg->f_zero = 0;
	arg->f_minus = 0;
	arg->f_plus = 0;
	arg->f_space = 0;
	arg->f_hashtag = 0;
	arg->f_prec = 0;
	arg->v_prec = 0;
	arg->f_field = 0;
	arg->v_len = 0;
	arg->nb_char = 0;
	arg->format = (void *)0;
	arg->mod = NULL;
	arg->conv = 0;
}

int		is_conversion(char c)
{
	static const char	*conversions = "%sSpdDioOuUxXcC";
	int					i;

	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		fill_arg(t_arg *arg, char *format)
{
	int		i;

	i = 1;
	while (format[i] && !is_conversion(format[i]))
	{
		if (ft_get_index("hljz0123456789# -+.", format[i]) == -1)
			break ;
		i++;
	}
	if (format[i] == '\0')
		return (i);
	arg->conv = format[i];
	arg->format = ft_strsub(format, 0, i + 1);
	i = 1;
	while (arg->format[i] && arg->format[i] != arg->conv)
		set_flag(arg, arg->format, &i);
	return (i + 1);
}

void	set_flag(t_arg *arg, char *format, int *i)
{
	if (format[*i] == '0' && (*i)++)
		arg->f_zero = 1;
	else if (format[*i] == '+' && ++(*i))
		arg->f_plus = 1;
	else if (format[*i] == '-' && ++(*i))
		arg->f_minus = 1;
	else if (format[*i] == ' ' && ++(*i))
		arg->f_space = 1;
	else if (format[*i] == '#' && ++(*i))
		arg->f_hashtag = 1;
	else
		set_flag2(arg, format, i);
}

void	set_flag2(t_arg *arg, char *format, int *i)
{
	if (format[*i] >= '1' && format[*i] <= '9')
	{
		arg->f_field = 1;
		arg->v_len = ft_atoi(format + *i);
		(*i) += nbr_len(arg->v_len, 10) - (arg->v_len == 0);
	}
	else if (format[*i] == 'h' && format[*i + 1] == 'h' && ++(*i) && ++(*i))
		arg->mod = "hh";
	else if (format[*i] == 'h' && ++(*i))
		arg->mod = "h";
	else if (format[*i] == 'l' && format[*i + 1] == 'l' && ++(*i) && ++(*i))
		arg->mod = "ll";
	else if (format[*i] == 'l' && ++(*i))
		arg->mod = "l";
	else if (format[*i] == 'j' && ++(*i))
		arg->mod = "j";
	else if (format[*i] == 'z' && ++(*i))
		arg->mod = "z";
	else if (format[*i] == '.' && ++(*i) && (arg->f_prec = 1))
	{
		arg->v_prec = ft_atoi(format + *i);
		(*i) += nbr_len(arg->v_prec, 10) - (arg->v_prec == 0);
	}
	else
		++(*i);
}
