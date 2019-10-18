/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:50:12 by vincent           #+#    #+#             */
/*   Updated: 2019/09/22 23:40:54 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/get_next_line.h"
# include <math.h>

typedef struct	s_coords
{
	int	x;
	int	y;
	int	z;
	int	pos;
	int	colour;
	int	tmp;
}				t_coords;

typedef struct	s_math
{
	double	x_ang;
	double	y_ang;
	double	z_ang;
	double	zoom;
	int		z_mult;
	int		iso;
	double	rep_speed;
}				t_math;

typedef struct	s_line
{
	int				max_w;
	int				max_h;
	int				length;
	int				*xz;
	unsigned int	*colour;
	struct s_line	*next;
}				t_line;

typedef struct	s_image
{
	int				max_w;
	int				max_h;
	int				coldep;
	int				w;
	int				endian;
	int				w_unit;
	int				disco;
	int				z_col;
	char			*image;
	void			*img_ptr;
	void			*mlx_ptr;
	struct s_math	*math;
}				t_image;

t_line			*parse_map(char *file);
t_image			matrix_to_img(int ***matrix, t_image img);
t_image			draw_line(t_coords s, t_coords e, t_image img);
int				get_colour(int scol, int ecol, double dist);
int				key_pressed(int key, void *param);
int				key_released(int key, void *param);
t_image			find_key(int key, t_image img);
t_image			rot(t_image img, int key);
t_image			zoom(t_image img, int key);
t_image			z_mult(t_image img, int key);
t_image			iso(t_image img);
t_image			reset(t_image img, int key);
t_image			reset_img(t_image img, void *win_ptr, int width);
t_image			put_text(t_image img, void *win_ptr);
#endif
