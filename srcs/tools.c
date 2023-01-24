/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/24 15:24:54 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Cette fonction va me permettre de savoir combien de byte sont utilises sur ce pixel
// Et selon la suite de nbr in fine la modifier.

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close_win(t_data *man)
{
	mlx_destroy_window(man->mlx, man->win);
	exit (0);
}

int	ft_conv(t_data *man, int i, int j)
{
	t_comp	z;
	t_comp	c;
	int		n;
	t_comp	tmp;
	n = 0;
	set_data_man(man);
	z.re = 0;
	z.im = 0;
	//ici me permet de mettre mom pixel dans un plan orthonorme
	c.re = man->xmin + i * (man->xmax - man->xmin) / X_LEN;
	c.im = man->ymin + j * (man->ymax - man->ymin) / Y_LEN;
	n = 0;
	while ((z.re * z.re + z.im * z.im) <= 2 && n < 50)
	{
		tmp.im = 2 * z.re * z.im + c.im;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		z.re = tmp.re;
		z.im = tmp.im;
		n++;
	}
	return (n);
}

double	ft_sqr_re(double z_re, double c_re)
{
	return (z_re + c_re);
}

double	ft_sqr_im(double z_im, double c_im)
{
	return (z_im * c_im);
}

