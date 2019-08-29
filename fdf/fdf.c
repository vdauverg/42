/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/29 15:48:32 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	mat_to_img(void *mlx_ptr, void *win_ptr, t_line *mat, t_image img)
{
	int		i;
	int		j;
	int		tot_len;
	double	pos;
	double	w_unit;

	if (mat->max_w > mat->max_h)
		w_unit = (double)(img.w / mat->max_w);
	else
		w_unit = (double)(img.w / mat->max_h);
	tot_len = img.w * img.w * img.coldep;
	i = 0;
	pos = 0.0;
	while (i < tot_len)
	{
		if ((i / img.coldep) == ((pos < (int)pos + 0.5) ? (int)pos : (int)pos + 1) && ((((i / img.coldep) / img.w) % (int)w_unit == 1) || !i))
		{
			j = 0;
			pos += w_unit;
			while (j < img.coldep)
			{
				img.image[i] = mlx_get_color_value(mlx_ptr, mat->colour[(int)(i / (img.coldep * w_unit)) % mat->max_w] >> j * 8);
				j++;
				i++;
			}
		}
		else
			i += img.coldep;
		if ((i / img.coldep) % img.w == 0)
			pos = i / img.coldep;
	}
	return (img);
}

t_image	create_image(void *mlx_ptr, t_image specs)
{
	specs.coldep = 4;
	specs.endian = 0;
	specs.img_ptr = mlx_new_image(mlx_ptr, specs.w, specs.w);
	specs.image = mlx_get_data_addr(specs.img_ptr, &specs.coldep, &specs.w, &specs.endian);
	specs.coldep /= 8;
	specs.w /= specs.coldep;
	return (specs);
}

int main(int argc, char **argv)
{
	int		width;
	void    *mlx_ptr;
	void    *win_ptr;
	t_line	*mat;
	t_image	img;

	if (argc == 2 && (mat = parse_map(argv[1])))
	{
		width = 900;
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, width, width, "FDF");
		img.w = width * 0.9;
		img = create_image(mlx_ptr, img);
		mat_to_img(mlx_ptr, win_ptr, mat, img);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, width * 0.05, width * 0.05);
		mlx_loop(mlx_ptr);
		for (int i = 0; i < 1; i++)
		{
			// if (i % 100 == 0)
			// {
				diff += 25;
				draw_image(mlx_ptr, win_ptr, img_ptr, w, diff);
				mlx_expose_hook(win_ptr, NULL, img_ptr);
			// }
		}
	}
	return (0);
}

int	draw_image(void *mlx_ptr, void *win_ptr, void *img_ptr, int w, int diff)
{
	int		colour;
	int		coldep;
	int		endian;
	char	*map;

	coldep = 4;
	endian = 0;
	w *= coldep;
	map = mlx_get_data_addr(img_ptr, &coldep, &w, &endian);
	coldep /= 8;
	w /= coldep;
	for (int i = 0; i < (w * w * coldep); i++)
	{
		if (!i || !(i % 4))
			colour = (200 + diff) % 255;
		else if (i % 4 == 1)
			colour = (100 + diff - 5) % 255;
		else if (i % 4 == 2)
			colour = (0 + diff + 34) % 255;
		else
			colour = 0;
		map[i] = mlx_get_color_value(mlx_ptr, colour);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	return (1);
}