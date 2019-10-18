/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:05:22 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 19:13:34 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	z_mult(t_image img, int key)
{
	if (key == 24)
		img.math->z_mult += 1 * img.math->rep_speed;
	else if (key == 27)
		img.math->z_mult -= 1 * img.math->rep_speed;
	return (img);
}

t_image	zoom(t_image img, int key)
{
	if (key == 69 && img.math->zoom < 1000)
		img.math->zoom *= 1 + (0.03 * (img.math->rep_speed));
	else if (key == 78)
		img.math->zoom /= 1 + (0.03 * (img.math->rep_speed));
	if (img.math->zoom > 1000)
		img.math->zoom = 1000;
	else if (img.math->zoom < 0.002)
		img.math->zoom = 0.002;
	return (img);
}

t_image	rot(t_image img, int key)
{
	if (key == 47 && ((img.math->z_ang += 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->z_ang > 6.28) ? img.math->z_ang -= 6.28 : 0;
	else if (key == 43 && ((img.math->z_ang -= 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->z_ang < 0) ? img.math->z_ang += 6.28 : 0;
	else if (key == 124 && ((img.math->y_ang += 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->y_ang > 6.28) ? img.math->y_ang -= 6.28 : 0;
	else if (key == 123 && ((img.math->y_ang -= 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->y_ang < 0) ? img.math->y_ang += 6.28 : 0;
	else if (key == 126 && ((img.math->x_ang += 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->x_ang > 6.28) ? img.math->x_ang -= 6.28 : 0;
	else if (key == 125 && ((img.math->x_ang -= 0.05 * img.math->rep_speed) \
			|| 1))
		(img.math->x_ang < 0) ? img.math->x_ang += 6.28 : 0;
	return (img);
}

t_image	iso(t_image img)
{
	img.math->iso = 1;
	return (img);
}

t_image	put_text(t_image img, void *win_ptr)
{
	char *tmp;

	tmp = ft_strjoinfreelast("Speed: x", ft_ftoa(img.math->rep_speed, 1, 0));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 10, 0x77FF55, tmp);
	free(tmp);
	tmp = ft_strjoinfreelast("X Angle: ", ft_ftoa(img.math->x_ang, 3, 0));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 30, 0x77FF55, tmp);
	free(tmp);
	tmp = ft_strjoinfreelast("Y Angle: ", ft_ftoa(img.math->y_ang, 3, 0));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 50, 0x77FF55, tmp);
	free(tmp);
	tmp = ft_strjoinfreelast("Z Angle: ", ft_ftoa(img.math->z_ang, 3, 0));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 70, 0x77FF55, tmp);
	free(tmp);
	tmp = ft_strjoinfreelast("Zoom: x", ft_ftoa(img.math->zoom, 3, 0));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 90, 0x77FF55, tmp);
	free(tmp);
	tmp = ft_strjoinfreelast("Height: x", ft_itoa(img.math->z_mult));
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 110, 0x77FF55, tmp);
	free(tmp);
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 130, 0x77FF55, (img.z_col) ? \
			"Colour Mode: Topographical" : "Colour Mode: Normal");
	mlx_string_put(img.mlx_ptr, win_ptr, 10, 170, 0xF44336, (img.disco) ? \
			"DISCO TIME!" : "D???? ?????");
	return (img);
}
