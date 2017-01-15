/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 20:32:54 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/26 21:16:04 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <mlx.h>

t_img	*ft_new_image(int width, int height, void *mlx)
{
	t_img	*img;
	void	*d;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	img->endian = 0;
	img->width = width;
	img->p_img = mlx_new_image(mlx, width, height);
	if (!img->p_img)
	{
		free(img);
		return (NULL);
	}
	d = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->data = d;
	img->max_size = (img->bpp / 8) * width * height;
	return (img);
}

void	add_pix_to_img(t_img *img, t_pix point, int color)
{
	long	position;
	int		octet;

	octet = img->bpp / 8;
	position = point.y * img->width + point.x * octet;
	ft_memcpy(img->data + position, &color, (unsigned)octet);
}
