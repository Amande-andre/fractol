/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 18:14:15 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_mande(t_data *f)
{
	int		n;

	f->x = 0;
	while (f->x < X_LEN)
	{
		f->y = 0;
		while (f->y < Y_LEN)
		{
			n = ft_conv(f, f->x, f->y);
			f->color = 255 - 255.0 * ((double) n) / 20;
			if (n == 0)
				n++;
			if (n == f->itteration)
			{
				my_mlx_pixel_put(f, f->x, f->y, 0);
			}
			else
				my_mlx_pixel_put(f, f->x, f->y, f->color / n * Y_LEN);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	set_data_man(t_data *f)
{
	f->ymax = 2;
	f->ymin = -2;
	f->xmin = -2;
	f->xmax = 2;
	f->itteration = 500;
	f->color = 0x0000FF;
	f->zoom = 0.9;
	f->xp = 0;
	f->yp = 0;
	f->h = 0;
	f->c.re = 0.1;
	f->c.im = 0.1;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, Y_LEN, X_LEN, "Mandelbrot");
	f->img = mlx_new_image(f->mlx, Y_LEN, X_LEN);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	f;
	(void)ac;
	if (ft_param(&f, av[1]) == 1)
		return (0);
	set_data_man(&f);
	mlx_hook(f.win, 17, 0, ft_close_win2, &f);
	mlx_hook(f.win, KeyPress, KeyPressMask, ft_close_win, &f);
	mlx_key_hook(f.win, ft_move, &f);
	mlx_mouse_get_pos(f.mlx, f.win, &f.xp, &f.yp);
	mlx_mouse_hook(f.win, ft_mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
