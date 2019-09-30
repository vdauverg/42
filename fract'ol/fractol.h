/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:38:11 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/29 18:10:40 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define MAX_ITER 50

typedef struct	s_image
{
	int			tot;
	int			w;
	int			h;
	int			col;
	double		cx;
	double		cy;
	double		jx;
	double		jy;
	double		x_diff;
	double		y_diff;
	char		*image;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_image;

void			display_fractol(t_image *img, int (*fractol)(double, \
						double, t_image));
int				zoom_mandelbrot(int btn, int x, int y, void *param);
int				zoom_burning_ship(int btn, int x, int y, void *param);
int				key_pressed(int key, void *param);
int				mouse_moved(int x, int y, void *param);
void			mandelbrot_init(t_image img);
void			julia_init(t_image img);
void			burning_ship_init(t_image img);
int				mandelbrot(double x, double y, t_image img);
int				julia(double x, double y, t_image img);
int				burning_ship(double x, double y, t_image img);
#endif
