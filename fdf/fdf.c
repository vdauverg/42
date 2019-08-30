/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/29 21:18:06 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	line_to_img(void *mlx_ptr, t_line *mat, t_image img, int iter)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->length)
	{
		j = 0;
		while (j < img.coldep)
		{
			img.image[(iter * img.w * (img.w_unit / img.coldep)) + (i * \
					img.w_unit) + j] = mlx_get_color_value(mlx_ptr, \
					mat->colour[i] >> (j * 8));
			j++;
		}
		i++;
	}
	return (img);
}

t_image	mat_to_img(void *mlx_ptr, t_line *mat, t_image img)
{
	int	i;

	if (mat->max_w > mat->max_h)
		img.w_unit = (img.w / mat->max_w);
	else
		img.w_unit = (img.w / mat->max_h);
	i = 0;
	while (mat)
	{
		img = line_to_img(mlx_ptr, mat, img, i);
		mat = mat->next;
		i++;
	}
	return (img);
}

t_image	create_image(void *mlx_ptr, t_image specs)
{
	specs.coldep = 4;
	specs.endian = 0;
	specs.img_ptr = mlx_new_image(mlx_ptr, specs.w, specs.w);
	specs.image = mlx_get_data_addr(specs.img_ptr, &specs.coldep, &specs.w, \
			&specs.endian);
	specs.coldep /= 8;
	return (specs);
}

int	main(int argc, char **argv)
{
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	*mat;
	t_image	img;

	if (argc == 2 && (mat = parse_map(argv[1])))
	{
		width = 900;
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, width, width, "FDF");
		img.w = width * 0.9;
		img = create_image(mlx_ptr, img);
		mat_to_img(mlx_ptr, mat, img);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, width * 0.05, \
				width * 0.05);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
