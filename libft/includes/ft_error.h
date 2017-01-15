/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:45:14 by ftriquet          #+#    #+#             */
/*   Updated: 2016/05/07 11:11:38 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef struct				s_error
{
	int						code;
	char					*msg;
}							t_error;

extern const t_error		g_errtab[];

char						*ft_strerror(void);
void						ft_perror(char *msg);
#endif
