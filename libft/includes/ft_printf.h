/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:45:09 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 10:02:16 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <locale.h>
# include "libft.h"
# include <wchar.h>
# define MAX(a,b) ((a > b) ? a : b)
# define MIN(a,b) ((a < b) ? a : b)
# define PTF_BUFF_SIZE 4096
# define EOC "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[45m"
# define YELLOW "\x1b[33m"
# define CYAN "\x1b[36m"
# define BLUE "\x1b[34m"

typedef struct		s_arg
{
	char			f_zero;
	char			f_minus;
	char			f_plus;
	int				f_space;
	char			f_hashtag;
	char			f_prec;
	int				v_prec;
	char			f_field;
	int				v_len;
	char			*format;
	int				nb_char;
	char			*mod;
	char			conv;
	char			buffer[PTF_BUFF_SIZE];
	size_t			curs;
	int				ret;
	int				err;
	int				fd;
}					t_arg;

char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_dprintf(int fd, char *format, ...);
int					ft_printf(char *format, ...);
void				set_flag(t_arg *arg, char *format, int *i);
void				set_flag2(t_arg *arg, char *format, int *i);
int					fill_arg(t_arg *arg, char *format);
int					is_conversion(char c);
void				init_arg(t_arg *arg);
char				*ft_itoa(intmax_t n, int base, int maj);
char				*ft_itoa_u(uintmax_t n, int base, int maj);
char				digit(int nb, int maj);
int					nbr_len_u(uintmax_t n, int base);
int					nbr_len(intmax_t nb, int base);
int					add_string_to_buffer(t_arg *arg, char *str);
int					add_char_to_buffer(t_arg *arg, char c);
int					add_int_to_buffer(t_arg *arg, intmax_t n,
		int base, int maj);
int					add_uint_to_buffer(t_arg *arg, uintmax_t n,
		int base, int maj);
void				handle_uxo(t_arg *arg, va_list ap);
void				handle_d(t_arg *arg, va_list ap);
void				handle_c(t_arg *arg, va_list ap);
void				print_s(t_arg *arg, void *s);
int					handle_s(t_arg *arg, va_list ap);
void				make_padding(t_arg *arg);
void				print_wchar2(t_arg *arg, unsigned int c);
void				print_wchar1(t_arg *arg, unsigned int c);
void				print_wchar3(t_arg *arg, unsigned int c);
void				print_wchar4(t_arg *arg, unsigned int c);
int					putnwchar(t_arg *arg, wchar_t *ch, int n);
int					putnstr(t_arg *arg, char *s, int n);
int					get_nb_octs(unsigned int c);
void				flush_buffer(t_arg *arg);
void				handle_other(t_arg *arg);
int					handle_conv(t_arg *arg, va_list ap, char *format, int *i);
void				init_printf(t_arg *arg, int fd);
int					handle_color(t_arg *arg, char *format, int *i);
int					is_color(t_arg *arg, char *format);
void				put_wchar(t_arg *arg, unsigned int c);
#endif
