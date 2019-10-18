/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:25:38 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/29 19:27:00 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burning_ship(double x, double y, t_image img)
{
	int		n;
	double	r;
	double	i;
	double	z;
	double	pr;

	x = -x;
	y = -y;
	n = -1;
	r = 0;
	i = 0;
	z = 0;
	pr = 0;
	while (r + i <= 4 && ++n < MAX_ITER)
	{
		r = fabs(pr - i + x);
		i = fabs(z - pr - i + y);
		z = (r * i) * 2;
		r *= r;
		i *= i;
		z += r + i;
		pr = r;
	}
	z = img.cy;
	return ((n == MAX_ITER) ? 0.0 : n * (0x0000FF / MAX_ITER));
}

int		julia(double x, double y, t_image img)
{
	int		n;
	double	c;
	double	z;

	n = 0;
	while (x + y <= 16 && n < MAX_ITER)
	{
		c = x * x - y * y;
		z = 2 * x * y;
		x = c + img.jx;
		y = z + img.jy;
		n++;
	}
	return ((n == MAX_ITER) ? 0.0 : n * (0x0000FF / MAX_ITER));
}

int		mandelbrot(double x, double y, t_image img)
{
	int		n;
	double	r;
	double	i;
	double	z;
	double	pr;

	n = 0;
	r = 0;
	i = 0;
	z = 0;
	pr = 0;
	while (r + i <= 4 && n < MAX_ITER)
	{
		r = (pr - i + x);
		i = (z - pr - i + y);
		z = (r * i) * 2;
		r *= r;
		i *= i;
		z += r + i;
		pr = r;
		n++;
	}
	z = img.cy;
	return ((n == MAX_ITER) ? 0.0 : n * (0xFFFFFF / MAX_ITER));
}
