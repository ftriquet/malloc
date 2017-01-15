/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:26:36 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/05 17:38:19 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct			s_buffline
{
	char				*buff;
	int					fd;
	struct s_buffline	*next;
}						t_buffline;
t_buffline				*new_buff(int const fd, t_buffline *next);
void					get_buffer(int const fd, t_buffline **first);
int						get_next_line(int const fd, char **line);
int						gnl(int const fd, char **line, t_buffline *b);
#endif
