/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/09/22 20:04:56 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	img.max_w = mat->max_w;
	img.max_h = mat->max_h;
	img.disco = 0;
	img.z_col = 0;
	img.math = (t_math *)malloc(sizeof(t_math));
	img.math->x_ang = 0;
	img.math->y_ang = 0;
	img.math->z_ang = 0;
	img.math->zoom = 0.65;
	img.math->z_mult = 1;
	img.math->iso = 0;
	img.math->rep_speed = 1;
	return (img);
}

int		main(int argc, char **argv)
{
	int		width;
	int		***matrix;
	void	*win_ptr;
	t_line	*mat;
	t_image	img;

	if (argc == 2 && (mat = parse_map(argv[1])))
	{
		width = 1200;
		img.mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(img.mlx_ptr, width, width, "vdauverg's FDF");
		img.w = width * 0.9;
		img = create_image(img, mat);
		matrix = create_matrix(mat);
		img = matrix_to_img(matrix, img);
		mlx_put_image_to_window(img.mlx_ptr, win_ptr, img.img_ptr, \
				width * 0.05, width * 0.05);
		img = put_text(img, win_ptr);
		mlx_hook(win_ptr, 2, 0, &key_pressed, (void*[4]){&img, matrix, \
				win_ptr, &width});
		mlx_hook(win_ptr, 3, 0, &key_released, (void*[4]){&img, matrix, \
				win_ptr, &width});
		mlx_loop(img.mlx_ptr);
	}
	return (0);
}
