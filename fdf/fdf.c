/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/10 21:40:51 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *img_ptr;
	t_line	*mat;
	int		diff;
	int		w;

	if (argc == 2)
	{
		mat = parse_map(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
		w = 300;
		img_ptr = mlx_new_image(mlx_ptr, w, w);
		diff = 0;
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