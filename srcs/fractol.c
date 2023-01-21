/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 15:05:49 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_mande(t_data *man, int color)
{
	while (man->x_len < X_LEN)
	{
		man->y_len = 0;
		while (man->y_len < Y_LEN)
		{
			if (ft_conv(man, man->x_len, man->y_len) >= INT_MAX)
			{
				my_mlx_pixel_put(man, man->x_len, man->y_len, 0);
			}
			else
				my_mlx_pixel_put(man, man->x_len, man->y_len, color);

			man->y_len++;
			printf("2\n");
		}
		man->x_len++;
		printf("3\n");
	}
	mlx_put_image_to_window(man->mlx, man->win, man->img, 0, 0);
	return (0);
}

int	main()
{
	t_data	man;
	int		color;

	man.left = (X_LEN * -1) + (X_LEN / 2);
	man.top = (Y_LEN / 2);
	man.x_len = 0;
	color = 0x0000FF;
	man.mlx = mlx_init();
	man.win = mlx_new_window(man.mlx, Y_LEN, X_LEN, "Mandelbrot");
	man.img = mlx_new_image(man.mlx, Y_LEN, X_LEN);
	man.addr = mlx_get_data_addr(man.img, &man.bits_per_pixel, &man.line_length, &man.endian);
	mlx_hook(man.win, 17, 0, ft_close_win, &man);
	ft_print_mande(&man, color);
	mlx_loop(man.mlx);
	return (0);
}