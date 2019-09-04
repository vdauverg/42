/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/09/03 15:07:51 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		get_colour(int scol, int ecol, double dist)
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
	return (((int)r << 16) + ((int)g << 8) + b);
}

int		get_next_pixel(t_image img, t_coords s, t_coords e, int iter)
{
	int		pos;
	int		x_dir;
	int		y_dir;
	double	m;

	m = (double)(e.y - s.y) / ((s.x != e.x) ? (e.x - s.x) : 1);
	(m < 0) ? m *= -1.0 : 0;
	x_dir = (e.x > s.x) ? 1 : -1;
	y_dir = (e.y > s.y) ? 1 : -1;
	(e.x == s.x) ? x_dir = 0 : 0;
	(e.y == s.y) ? y_dir = 0 : 0;
	if (m >= 1)
		x_dir *= (1.0 / m) * (iter % (int)m);
	else if (m < 1)
		y_dir *= m * iter;
	pos = y_dir * img.w + x_dir * img.coldep;
	return (pos);
}

t_image	draw_line(t_image img, t_coords s, t_coords e)
{
	int		i;
	int		j;
	int		pos;
	int		colour;

	pos = s.pos;
	colour = get_colour(s.colour, e.colour, sqrt(pow((double)(e.y - s.y), 2.0) \
			+ pow((double)(e.x - s.x), 2.0)));
	i = 0;
	while ((s.pos > e.pos) ? pos > e.pos : pos < e.pos)
	{
		j = 0;
		while (j < img.coldep)
		{
			img.image[pos + j] = mlx_get_color_value(img.mlx_ptr, (s.colour + \
					colour * (i + 1)) >> j * 8);
			j++;
		}
		pos += get_next_pixel(img, s, e, i);
		i++;
	}
	return (img);
}

t_image	matrix_to_img(int ***matrix, t_line *mat, t_image img)
{
	int		i;
	int		j;
	t_coords	s;
	t_coords	e;

	i = 0;
	while (i < mat->max_h)
	{
		j = 0;
		while (j < mat->max_w)
		{
			if (matrix[i][j + 1] && matrix[i][j][2] && matrix[i][j + 1][2])
			{
				s.x = j * img.w_unit;
				s.y = i * img.w_unit;
				s.colour = matrix[i][j][1];
				s.pos = i * img.w_unit * img.w + j * img.w_unit * img.coldep;
				e.x = (j + 1) * img.w_unit;
				e.y = i * img.w_unit;
				e.colour = matrix[i][j + 1][1];
				e.pos = i * img.w_unit * img.w + (j + 1) * img.w_unit * img.coldep;
				img = draw_line(img, s, e);
			}
			if (matrix[i + 1] && matrix[i][j][2] && matrix[i + 1][j][2])
			{
				s.x = j * img.w_unit;
				s.y = i * img.w_unit;
				s.colour = matrix[i][j][1];
				s.pos = i * img.w_unit * img.w + j * img.w_unit * img.coldep;
				e.x = j * img.w_unit;
				e.y = (i + 1) * img.w_unit;
				e.colour = matrix[i + 1][j][1];
				e.pos = (i + 1) * img.w_unit * img.w + j * img.w_unit * img.coldep;
				img = draw_line(img, s, e);
			}
			j++;
		}
		i++;
	}
	return (img);
}

int		***init_matrix(t_line *mat)
{
	int	i;
	int	j;
	int	***matrix;

	matrix = (int ***)malloc(sizeof(int **) * (mat->max_h + 1));
	matrix[mat->max_h] = NULL;
	i = 0;
	while (i < mat->max_h)
	{
		matrix[i] = (int **)malloc(sizeof(int *) * (mat->max_w + 1));
		matrix[i][mat->max_w] = NULL;
		j = 0;
		while (j < mat->max_w)
		{
			matrix[i][j] = (int *)malloc(sizeof(int) * 3);
			j++;
		}
		i++;
	}
	return (matrix);
}

int		***create_matrix(t_line *mat)
{
	int	i;
	int	j;
	int	max_w;
	int	***matrix;

	matrix = init_matrix(mat);
	max_w = mat->max_w;
	i = 0;
	while (mat)
	{
		j = -1;
		while (++j < max_w)
		{
			matrix[i][j][2] = 0;
			if (j < mat->length)
			{
				matrix[i][j][0] = mat->xz[j];
				matrix[i][j][1] = mat->colour[j];
				matrix[i][j][2] = 1;
			}
		}
		mat = mat->next;
		i++;
	}
	return (matrix);
}

t_image	create_image(t_image img, t_line *mat)
{
	img.coldep = 4;
	img.endian = 0;
	img.img_ptr = mlx_new_image(img.mlx_ptr, img.w, img.w);
	img.image = mlx_get_data_addr(img.img_ptr, &img.coldep, &img.w, \
			&img.endian);
	img.coldep /= 8;
	if (mat->max_w > mat->max_h)
		img.w_unit = (img.w / img.coldep) / mat->max_w;
	else
		img.w_unit = (img.w / img.coldep) / mat->max_h;
	return (img);
}

int	main(int argc, char **argv)
{
	int		width;
	int		***matrix;
	void	*win_ptr;
	t_line	*mat;
	t_image	img;
	// t_rot	rot;

	if (argc == 2 && (mat = parse_map(argv[1])))
	{
		width = 1200;
		img.mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(img.mlx_ptr, width, width, "FDF");
		img.w = width * 0.9;
		img = create_image(img, mat);
		matrix = create_matrix(mat);
		img = matrix_to_img(matrix, mat, img);
		mlx_put_image_to_window(img.mlx_ptr, win_ptr, img.img_ptr, width * 0.1, \
				width * 0.1);
		mlx_loop(img.mlx_ptr);
	}
	return (0);
}
