/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:16 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 20:13:30 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

int	ft_julia_param(t_data *f, char *av)
{
	if (av == NULL)
	{
		write(1, "use Julia 1 or Julia 2 as paramter", 35);
		return (1);
	}	
	if (ft_atoi(av) == 1)
	{
		f->c.im = -0.85;
		f->c.re = -0.301;
	}
	else if (ft_atoi(av) == 2)
	{
		f->c.im = 0.008;
		f->c.re = -0.79545;
	}
	else
	{
		write(1, "use Julia 1 or Julia 2 as paramter", 35);
		return (1);
	}
	f->set = 2;
	ft_print(f);
	return (0);
}

int	ft_conv_julia(t_data *f, double i, double j)
{
	t_comp	z;
	int		n;
	t_comp	tmp;

	n = 0;
	z.re = (double)(f->xmin + i * (f->xmax - f->xmin) / X_LEN);
	z.im = (double)(f->ymin + j * (f->ymax - f->ymin) / Y_LEN);
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
