/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 06:10:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/08 22:23:21 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(intmax_t nb, int base);
void	ft_putunbr(uintmax_t nb, int base);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
#endif
