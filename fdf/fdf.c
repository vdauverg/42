/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/10 14:33:11 by vincent          ###   ########.fr       */
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

	if (argc == 2)
	{
		mat = parse_map(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
		w = 300;
		img_ptr = mlx_new_image(mlx_ptr, w, w);
		coldep = 2;
		endian = 0;
		w *= coldep / 8;
		map = mlx_get_data_addr(img_ptr, &coldep, &w, &endian);
		w /= coldep / 8;
		for (int i = 0; i < (w * w * (coldep / 8)); i++)
			map[i] = mlx_get_color_value(mlx_ptr, (((255 & 0xFF) << 16) + ((30 & 0xFF) << 8) + (120 & 0xFF)));
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
		mlx_loop(mlx_ptr);
	}
	return (0);
}