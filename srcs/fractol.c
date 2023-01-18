/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/01/18 19:56:07 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		color;

	int x = 1;
	int y = 1;
	color = 0x99FFFF;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y++ < 300)
	{
		my_mlx_pixel_put(&img, x, y, color--);
		mlx_put_image_to_window(mlx, window, img.img, WIDTH / 2, LENGTH / 2);
	}
	while (x++ < 300)
	{
		my_mlx_pixel_put(&img, x, y, color);
		color += x;
	}
	while (y-- > 1)
	{
		my_mlx_pixel_put(&img, x, y, color);
		color += y;
	}
	while (x-- > 1)
	{
		my_mlx_pixel_put(&img, x, y, color);
		color += x;
	}

	mlx_loop(mlx);
	return (0);
}