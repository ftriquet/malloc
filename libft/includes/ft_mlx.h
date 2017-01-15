/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 20:33:58 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/28 16:00:18 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

typedef struct		s_img
{
	void			*p_img;
	char			*data;
	int				bpp;
	int				endian;
	int				width;
	int				max_size;
}					t_img;

typedef struct		s_pix
{
	int				x;
	int				y;
}					t_pix;

t_img				*ft_new_image(int width, int height, void *mlx);
void				add_pix_to_img(t_img *img, t_pix point, int color);

#endif
