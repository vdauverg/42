/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:00:30 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 18:55:45 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	reset_img(t_image img, void *win_ptr, int width)
{
	int	i;
	int	max;

	max = width * width * img.coldep;
	i = 0;
	mlx_clear_window(img.mlx_ptr, win_ptr);
	while (i < max)
		img.image[i++] = 0;
	return (img);
}

t_image	reset(t_image img, int key)
{
	img.math->x_ang = 0;
	img.math->y_ang = 0;
	img.math->z_ang = 0;
	if (key == 15)
	{
		img.math->zoom = 0.65;
		img.math->z_mult = 1;
	}
	return (img);
}

t_image	find_key(int key, t_image img)
{
	if (key == 69 || key == 78)
		img = zoom(img, key);
	else if (key == 24 || key == 27)
		img = z_mult(img, key);
	else if (key == 43 || key == 47 || key == 123 || key == 124 || key == 125 \
			|| key == 126)
		img = rot(img, key);
	else if (key == 15 || key == 31)
		img = reset(img, key);
	else if (key == 34)
		img = iso(img);
	else if (key == 8)
		img.z_col = (!img.z_col) ? 1 : 0;
	else if (key == 2)
		img.disco = (!img.disco) ? 1 : 0;
	else if (key == 53)
		exit(0);
	return (img);
}

int		key_released(int key, void *param)
{
	int		width;
	int		***matrix;
	void	**params;
	void	*win_ptr;
	t_image *img;

	params = param;
	img = (t_image *)params[0];
	matrix = (int ***)params[1];
	win_ptr = params[2];
	width = *(int *)params[3];
	img->math->rep_speed = 1;
	*img = reset_img(*img, win_ptr, width);
	*img = matrix_to_img(matrix, *img);
	mlx_put_image_to_window(img->mlx_ptr, win_ptr, img->img_ptr, width * 0.05,\
				width * 0.05);
	*img = put_text(*img, win_ptr);
	return (key);
}

int		key_pressed(int key, void *param)
{
	int		width;
	int		***matrix;
	void	*win_ptr;
	void	**params;
	t_image	*img;

	params = param;
	img = (t_image *)params[0];
	matrix = (int ***)params[1];
	win_ptr = params[2];
	width = *(int *)params[3];
	(img->math->rep_speed < 5) ? img->math->rep_speed += 0.1 : \
		(img->math->rep_speed = 5);
	*img = reset_img(*img, win_ptr, width);
	*img = find_key(key, *img);
	*img = matrix_to_img(matrix, *img);
	(img->math->iso) ? img->math->iso = 0 : 0;
	mlx_put_image_to_window(img->mlx_ptr, win_ptr, img->img_ptr, width * 0.05,\
				width * 0.05);
	*img = put_text(*img, win_ptr);
	return (key);
}
