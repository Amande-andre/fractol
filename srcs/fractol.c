/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/01/24 18:08:58 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_mande(t_data *man, int color)
{
	double	i;
	double	j;
	int		n;

	i= 0;
	(void)color;
	while (i < X_LEN)
	{
		j = 0;
		while (j < Y_LEN)
		{
			n = ft_conv(man, i, j);
			if (n == 50)
			{
				my_mlx_pixel_put(man, i, j, 0);
			}
			else
				my_mlx_pixel_put(man, i, j, color / n * X_LEN);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(man->mlx, man->win, man->img, 0, 0);
	return (0);
}

int	set_data_man(t_data *man)
{
	man->ymax = 2;
	man->ymin = -2;
	man->xmin = -2;
	man->xmax = 2;
	return (0);
}

int	main()
{
	t_data	man;
	int		color;

	man.x_pos = 0;
	color = 0x0000FF;
	man.h = 0;
	man.mlx = mlx_init();
	man.win = mlx_new_window(man.mlx, Y_LEN, X_LEN, "Mandelbrot");
	man.img = mlx_new_image(man.mlx, Y_LEN, X_LEN);
	man.addr = mlx_get_data_addr(man.img, &man.bits_per_pixel, &man.line_length, &man.endian);
	mlx_hook(man.win, 17, 0, ft_close_win, &man);
	mlx_hook(man.win, KeyPress, KeyPressMask, ft_close_win, &man);
	//mlx_hook(man.win, 4, 0, ft_zoom, &man);
	ft_print_mande(&man, color);
	mlx_loop(man.mlx);
	return (0);
}
