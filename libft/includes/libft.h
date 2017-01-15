/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:15:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/31 15:12:26 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# include <ft_list.h>
# include <ft_string.h>
# include <ft_mem.h>
# include <ft_display.h>
# include <ft_printf.h>
# include <ft_boolean.h>
# include <get_next_line.h>
# include <ft_mlx.h>
# include <ft_error.h>
# include <ft_slices.h>
# define SUCCESS 0
# define FAILURE 1

intmax_t	ft_atoi(const char *str);

char		*ft_itoa_u(uintmax_t n, int base, int maj);

char		*ft_itoa(intmax_t n, int base, int maj);

int			nbr_len_u(uintmax_t n, int base);

int			nbr_len(intmax_t nb, int base);
#endif
