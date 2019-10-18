/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:03:17 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 18:41:07 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	ft_rotate(t_coords coords, t_math *math)
{
	double	cosine;
	double	sine;

	if (math->x_ang && ((coords.tmp = coords.y) || 1))
	{
		cosine = cos(math->x_ang);
		sine = sin(math->x_ang);
		coords.y = (int)(coords.tmp * cosine - coords.z * sine);
		coords.z = (int)(coords.tmp * sine + coords.z * cosine);
	}
	if (math->y_ang && ((coords.tmp = coords.x) || 1))
	{
		cosine = cos(math->y_ang);
		sine = sin(math->y_ang);
		coords.x = (int)(coords.tmp * cosine + coords.z * sine);
		coords.z = (int)(-coords.tmp * sine + coords.z * cosine);
	}
	if (math->z_ang && ((coords.tmp = coords.x) || 1))
	{
		cosine = cos(math->z_ang);
		sine = sin(math->z_ang);
		coords.x = (int)(coords.tmp * cosine - coords.y * sine);
		coords.y = (int)(coords.tmp * sine + coords.y * cosine);
	}
	return (coords);
}

t_coords	rot_iso(t_coords coords)
{
	coords.x = (coords.x + coords.y) * cos(0.523599);
	coords.y = (coords.x - coords.y) * -sin(0.523599) - coords.z;
	return (coords);
}

int			get_z_col(int z)
{
	int	col;

	if (!z)
		col = 0xFFFFFF;
	else if (z <= 75)
		col = 0xFFFFFF + z * (get_colour(0xFFFFFF, 0x5555FF, 75));
	else if (z <= 150)
		col = 0x5555FF + (z - 75) * (get_colour(0x5555FF, 0x55FFFF, 75));
	else if (z <= 225)
		col = 0x55FFFF + (z - 150) * (get_colour(0x55FFFF, 0x55FF55, 75));
	else if (z <= 300)
		col = 0x55FF55 + (z - 225) * (get_colour(0x55FF55, 0xFFFF55, 75));
	else if (z <= 375)
		col = 0xFFFF55 + (z - 300) * (get_colour(0xFFFF55, 0xFF5555, 75));
	else
		col = 0xFF5555;
	return (col);
}

t_coords	coords_init(int ***matrix, int i, int j, t_image img)
{
	int			cx;
	int			cy;
	t_coords	coords;

	cx = (img.max_w / 2) * img.w_unit;
	cy = (img.max_h / 2) * img.w_unit;
	coords.x = j * img.w_unit - cx;
	coords.x *= img.math->zoom;
	coords.y = i * img.w_unit - cy;
	coords.y *= img.math->zoom;
	coords.z = matrix[i][j][0] * img.math->z_mult;
	(img.z_col) ? coords.colour = get_z_col(abs(coords.z)) : \
			(coords.colour = matrix[i][j][1]);
	coords.z *= img.math->zoom;
	if (!img.math->iso)
		coords = ft_rotate(coords, img.math);
	else
		coords = rot_iso(coords);
	if (img.max_w > img.max_h)
		coords.y += (img.w / img.coldep - (img.max_h * img.w_unit)) / 2;
	else
		coords.x += (img.w / img.coldep - (img.max_w * img.w_unit)) / 2;
	coords.x += cx;
	coords.y += cy;
	return (coords);
}

t_image		matrix_to_img(int ***matrix, t_image img)
{
	int			i;
	int			j;
	t_coords	s;
	t_coords	e;

	i = -1;
	while (matrix[++i] && (j = -1))
	{
		while (matrix[i][++j])
		{
			if (matrix[i][j + 1] && matrix[i][j][2] && matrix[i][j + 1][2])
			{
				s = coords_init(matrix, i, j, img);
				e = coords_init(matrix, i, j + 1, img);
				img = draw_line(s, e, img);
			}
			if (matrix[i + 1] && matrix[i][j][2] && matrix[i + 1][j][2])
			{
				s = coords_init(matrix, i, j, img);
				e = coords_init(matrix, i + 1, j, img);
				img = draw_line(s, e, img);
			}
		}
	}
	return (img);
}
