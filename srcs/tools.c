/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 13:58:15 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_conv(t_data *f, double i, double j)
{
	t_comp	z;
	t_comp	c;
	int		n;
	t_comp	tmp;

	n = 0;
	z.re = 0;
	z.im = 0;
	c.re = f->xmin + i * (f->xmax - f->xmin) / X_LEN;
	c.im = f->ymin + j * (f->ymax - f->ymin) / Y_LEN;
	n = 0;
	while (z.re * z.re + z.im * z.im <= (double)4 && n < f->itteration)
	{
		tmp.im = 2 * z.re * z.im + c.im;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		z.re = tmp.re;
		z.im = tmp.im;
		n++;
	}
	return (n);
}

int	ft_mouse_hook(int code, int x, int y, t_data *f)
{
	if (code == 4 || code == 1)
	{
		ft_zoom(x, y, f);
	}
	else if ((code == 5 || code == 2) && f->h >= 0)
	{
		ft_dezoom(x, y, f);
	}
	return (1);
}

int	ft_zoom(int x, int y, t_data *f)
{
	float	xdelta;
	float	ydelta;
	float	xp;
	float	yp;

	x = y;
	xdelta = (f->xmax - f->xmin);
	ydelta = (f->ymax - f->ymin);
	xp = ((double)f->xp / (X_LEN / xdelta)) + f->xmin;
	yp = (((double)f->yp / (Y_LEN / ydelta)) - f->ymax) * -1;
	f->ymax = (f->ymax * f->zoom);
	f->ymin = (f->ymin * f->zoom);
	f->xmin = (f->xmin * f->zoom);
	f->xmax = (f->xmax * f->zoom);
	f->h++;
	f->itteration++;
	ft_print(f);
	return (x);
}

int	ft_dezoom(int x, int y, t_data *f)
{
	x = y;
	mlx_mouse_get_pos(f->mlx, f->win, &f->xp, &f->yp);
	f->ymax = f->ymax * 1.1;
	f->ymin = f->ymin * 1.1;
	f->xmin = f->xmin * 1.1;
	f->xmax = f->xmax * 1.1;
	if (f->itteration > 50)
		f->itteration--;
	f->h--;
	ft_print(f);
	return (x);
}

int	ft_print(t_data *f)
{
	if (f->set == 1)
		ft_print_mande(f);
	else if (f->set == 2)
		ft_print_julia(f);
	return (0);
}
