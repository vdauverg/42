/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:27:26 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/29 20:16:14 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	safe_exit(int err)
{
	if (!err)
		ft_putstr\
("Not a valid set.\nUsage: ./fractol <['mandelbrot', 'julia', 'burningship']>");
	exit(0);
}

t_image	create_image(t_image img)
{
	int	coldep;
	int	endian;

	coldep = 4;
	endian = 0;
	img.img_ptr = mlx_new_image(img.mlx_ptr, img.w, img.h);
	img.image = mlx_get_data_addr(img.img_ptr, &coldep, &img.w, &endian);
	img.w /= 4;
	img.tot = img.w * img.h * 4;
	img.col = 0;
	return (img);
}

int		key_pressed(int key, void *param)
{
	t_image *img;

	img = (t_image *)param;
	if (key == 53)
		safe_exit(1);
	else if (key == 24)
		img->col = (img->col + 500000) % 0xFFFFFF;
	else if (key == 27)
		img->col = abs(img->col - 500000) % 0xFFFFFF;
	return (key);
}

int		main(int argc, char **argv)
{
	t_image	img;

	if (argc == 2)
	{
		img.w = 500;
		img.h = (img.w / 3) * 2;
		img.mlx_ptr = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx_ptr, img.w, img.h, \
				"vdauverg's fract'ol");
		img = create_image(img);
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mandelbrot_init(img);
		else if (!ft_strcmp(argv[1], "julia"))
			julia_init(img);
		else if (!ft_strcmp(argv[1], "burningship"))
			burning_ship_init(img);
		else
			safe_exit(0);
		mlx_loop(img.mlx_ptr);
	}
	else
		ft_putstr("Usage: ./fractol <['mandelbrot', 'julia', 'burningship']>");
	return (0);
}
