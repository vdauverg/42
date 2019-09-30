/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 01:49:52 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/29 19:26:35 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship_init(t_image img)
{
	img.cx = 0.5;
	img.cy = 0.5;
	img.x_diff = 3.0;
	img.y_diff = 3.0;
	display_fractol(&img, &burning_ship);
	mlx_mouse_hook(img.win_ptr, &zoom_burning_ship, &img);
}

void	julia_init(t_image img)
{
	img.cx = 0;
	img.cy = 0;
	img.x_diff = 3.0;
	img.y_diff = 2.0;
	img.jx = 0;
	img.jy = 0;
	display_fractol(&img, &julia);
	mlx_hook(img.win_ptr, 6, 0, &mouse_moved, &img);
}

void	mandelbrot_init(t_image img)
{
	img.cx = -0.5;
	img.cy = 0;
	img.x_diff = 3.0;
	img.y_diff = 2.0;
	display_fractol(&img, &mandelbrot);
	mlx_mouse_hook(img.win_ptr, &zoom_mandelbrot, &img);
}

int		draw_pixel(t_image *img, int col, int i)
{
	int	j;

	j = 0;
	(col) ? col += img->col : 0;
	while (j < 4)
	{
		img->image[i + j] = mlx_get_color_value(img->mlx_ptr, col >> (j * 8));
		j++;
	}
	return (i + j);
}

void	display_fractol(t_image *img, int (*fractol)(double, double, t_image))
{
	int		i;
	double	x_diff;
	double	y_diff;
	double	x;
	double	y;

	i = 0;
	x_diff = img->x_diff / img->w;
	y_diff = img->y_diff / img->h;
	x = img->cx - img->x_diff / 2;
	y = img->cy + img->y_diff / 2;
	while (i < img->tot)
	{
		i = draw_pixel(img, fractol(x, y, *img), i);
		x += x_diff;
		if (i && i % (img->w * 4) == 0)
		{
			x = img->cx - img->x_diff / 2;
			y -= y_diff;
		}
	}
	mlx_key_hook(img->win_ptr, &key_pressed, img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, \
			0, 0);
}
