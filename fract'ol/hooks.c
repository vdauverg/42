/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:27:52 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/29 19:28:29 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_moved(int x, int y, void *param)
{
	t_image *img;

	img = (t_image *)param;
	if (x > 0 && x < img->w && y > 0 && y < img->h)
	{
		img->jx = (img->x_diff / img->w) * (x - img->w / 2);
		img->jy = (img->y_diff / img->h) * (-y + img->h / 2);
	}
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	display_fractol(img, &julia);
	return (x + y);
}

int		zoom_burning_ship(int btn, int x, int y, void *param)
{
	t_image *img;

	img = (t_image *)param;
	x -= img->w / 2;
	y -= img->h / 2;
	img->cx += (img->x_diff / img->w) * x;
	img->cy -= (img->y_diff / img->h) * y;
	if (btn == 1 || btn == 4)
	{
		img->x_diff *= 0.9;
		img->y_diff *= 0.9;
	}
	else if (btn == 2 || btn == 5)
	{
		img->x_diff /= 0.9;
		img->y_diff /= 0.9;
	}
	img->cx -= (img->x_diff / img->w) * x;
	img->cy += (img->y_diff / img->h) * y;
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	display_fractol(img, &burning_ship);
	return (btn);
}

int		zoom_mandelbrot(int btn, int x, int y, void *param)
{
	t_image *img;

	img = (t_image *)param;
	x -= img->w / 2;
	y -= img->h / 2;
	img->cx += (img->x_diff / img->w) * x;
	img->cy -= (img->y_diff / img->h) * y;
	if (btn == 1 || btn == 4)
	{
		img->x_diff *= 0.9;
		img->y_diff *= 0.9;
	}
	else if (btn == 2 || btn == 5)
	{
		img->x_diff /= 0.9;
		img->y_diff /= 0.9;
	}
	img->cx -= (img->x_diff / img->w) * x;
	img->cy += (img->y_diff / img->h) * y;
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	display_fractol(img, &mandelbrot);
	return (btn);
}
