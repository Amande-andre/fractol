/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/01/25 18:47:17 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_mande(t_data *man, int color)
{
	int		n;

	man->x = 0;
	while (man->x < X_LEN)
	{
		man->y = 0;
		while (man->y < Y_LEN)
		{
			n = ft_conv(man, man->x, man->y);
			if (n == man->itteration)
			{
				my_mlx_pixel_put(man, man->x, man->y, 0);
			}
			else
				my_mlx_pixel_put(man, man->x, man->y, color / n * Y_LEN);
			man->y++;
		}
		man->x++;
	}
	mlx_put_image_to_window(man->mlx, man->win, man->img, 0, 0);
	return (0);
}

int	set_data_man(t_data *man)
{
	man->ymax = 2 ;
	man->ymin = -2;
	man->xmin = -2;
	man->xmax = 2;
	return (0);
}

int	main()
{
	t_data	man;
	int		color;

	color = 0x0000FF;
	man.h = 0;
	man.itteration = 50;
	man.mlx = mlx_init();
	man.win = mlx_new_window(man.mlx, Y_LEN, X_LEN, "Mandelbrot");
	man.img = mlx_new_image(man.mlx, Y_LEN, X_LEN);
	man.addr = mlx_get_data_addr(man.img, &man.bits_per_pixel, &man.line_length, &man.endian);
	set_data_man(&man);
	ft_print_mande(&man, color);
	mlx_hook(man.win, 17, 0, ft_close_win2, &man);
	mlx_hook(man.win, KeyPress, KeyPressMask, ft_close_win, &man);
	printf("3\n");
	mlx_mouse_hook(man.win, ft_mouse_hook, &man);
	mlx_loop(man.mlx);
	return (0);
}
