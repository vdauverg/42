/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/12 01:01:19 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *img_ptr;
	char	*map;
	t_line	*mat;
	int		coldep;
	int		endian;
	int		w;
	int		colour;

	if (argc == 2)
	{
		mat = parse_map(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
		w = 300;
		img_ptr = mlx_new_image(mlx_ptr, w, w);
		coldep = 3;
		endian = 0;
		w *= coldep;
		map = mlx_get_data_addr(img_ptr, &coldep, &w, &endian);
		coldep /= 8;
		w /= coldep;
		colour = 0;
		for (int i = 0; i < (w * w * coldep); i++)
		{
			if (i && i % (w * coldep) == 0)
				mat = mat->next;
			if (!mat)
				break ;
			colour = mat->colour[(int)((i % (w * coldep)) * (double)(mat->length / (w * coldep)))];
			map[i] = mlx_get_color_value(mlx_ptr, colour);
		}
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
		mlx_loop(mlx_ptr);
	}
	return (0);
}