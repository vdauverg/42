/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/14 20:08:19 by vincent          ###   ########.fr       */
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
	pos = 0;
	while (i < tot_len)
	{
		if (i / img.coldep == (pos < (int)pos + 0.5) ? (int)pos : (int)pos + 1)
		{
			j = 0;
			pos += w_unit;
			while (j < 4)
			{
				img.image[i] = mlx_get_color_value(mlx_ptr, mat->colour[i / img.coldep] >> (img.coldep - (4 * j)));
				j++;
				i++;
			}
		}
		else
			i += img.coldep;
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

	if (argc == 2)
	{
		width = 500;
		mat = parse_map(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, width, width, "FDF");
		img.w = width * 0.9;
		img = create_image(mlx_ptr, img);
		mat_to_img(mlx_ptr, win_ptr, mat, img);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, width * 0.05, width * 0.05);
		mlx_loop(mlx_ptr);
	}
	return (0);
}