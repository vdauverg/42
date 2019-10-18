/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:53:40 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 19:01:10 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	draw_pixel(int x, int y, t_image img, int col)
{
	int	i;
	int	pos;
	int	posx;
	int	posy;

	if (x < 0 || y < 0)
		return (img);
	posx = x * img.coldep;
	if (posx >= img.w)
		return (img);
	posy = y * img.w;
	if (posy > img.w * img.w)
		return (img);
	pos = posx + posy;
	i = 0;
	while (i < 4)
	{
		img.image[pos + i] = mlx_get_color_value(img.mlx_ptr, col >> i * 8);
		i++;
	}
	return (img);
}

int		get_colour(int scol, int ecol, double dist)
{
	double	r;
	double	g;
	double	b;

	r = (ecol >> 16) - (scol >> 16);
	g = ((ecol >> 8) & 255) - ((scol >> 8) & 255);
	b = (ecol & 255) - (scol & 255);
	r /= dist;
	g /= dist;
	b /= dist;
	return (((int)r << 16) + ((int)g << 8) + (int)b);
}

t_image	draw_line(t_coords s, t_coords e, t_image img)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	col;

	dx = abs(e.x - s.x);
	dy = -abs(e.y - s.y);
	err = dx + dy;
	if (img.disco && ((s.colour = abs(s.z * 100000)) || 1))
		e.colour = abs(e.z * 100000);
	col = get_colour(s.colour, e.colour, sqrt(pow(dx, 2) + pow(dy, 2)));
	while (!(s.x == e.x && s.y == e.y) && ((s.colour += col) || 1))
	{
		if ((s.x < 0 && e.x < 0) || (s.y < 0 && e.y < 0) || (s.x * img.coldep \
		> img.w && e.x * img.coldep > img.w) || (s.y > img.w && e.y > img.w))
			break ;
		e2 = err + err;
		if (e2 >= dy && ((err += dy) || 1))
			s.x += ((s.x < e.x) ? 1 : -1);
		if (e2 <= dx && ((err += dx) || 1))
			s.y += ((s.y < e.y) ? 1 : -1);
		img = draw_pixel(s.x, s.y, img, s.colour);
	}
	return (img);
}
