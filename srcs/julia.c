/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:16 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 17:58:48 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_julia(t_data *f)
{
	int		n;

	f->x = 0;
	while (f->x < X_LEN)
	{
		f->y = 0;
		while (f->y < Y_LEN)
		{
			n = ft_conv_julia(f, f->x, f->y);
			f->color = 255 - 255.0 * ((double) n) / 20;
			if (n == 0)
				n++;
			if (n == f->itteration)
				my_mlx_pixel_put(f, f->x, f->y, 0);
			else
				my_mlx_pixel_put(f, f->x, f->y, f->color / n * Y_LEN);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}


int	ft_conv_julia(t_data *f, double i, double j)
{
	t_comp	z;
	int		n;
	t_comp	tmp;
	n = 0;
	z.re = (double) (f->xmin + i * (f->xmax - f->xmin) / X_LEN);
 	z.im = (double) (f->ymin + j * (f->ymax - f->ymin) / Y_LEN);
	n = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && n < f->itteration)
	{
		tmp.im = 2 * z.re * z.im + f->c.im;
		tmp.re = z.re * z.re - z.im * z.im + f->c.re;
		z.re = tmp.re;
		z.im = tmp.im;
		n++;
	}
	return (n);
}
