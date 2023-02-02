/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 17:00:22 by anmande          ###   ########.fr       */
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

int	ft_close_win(int key, t_data *f)
{
	if (key == XK_Escape || key == 17)
    {
		mlx_destroy_window(f->mlx, f->win);
		exit (0);
	}
	return (0);
}

int	ft_close_win2(t_data *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit (0);
}
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
		ft_zoom(x, y, f);
	else if ((code == 5 || code == 2) && f->h >= 0)
		ft_dezoom(x, y, f);
	return (1);
}

int	ft_zoom(int x, int y, t_data *f)
{
	float	xdelta;
	float	ydelta;
	float	xp;
	float	yp;
	x = X_LEN / 3;
	y = Y_LEN / 3;
	xdelta = (f->xmax - f->xmin);
	ydelta = (f->ymax - f->ymin);
	mlx_destroy_image(f->mlx, f->img);
	mlx_mouse_get_pos(f->mlx, f->win, &f->xp, &f->yp);
	xp = ((double)f->xp / (X_LEN / xdelta)) + f->xmin;
	yp = (((double)f->yp / (Y_LEN / ydelta)) - f->ymax) * -1;
	if (xp > 0)
	{
		f->xmin -= xdelta * 0.05 + xp;
		f->xmax -= xdelta * 0.05 + xp;
	}
	else
	{
		f->xmin += xp * 0.5 * -1;
		f->xmax += xp * 0.5 * -1;
	}
	if (yp >= 0)
	{
		f->ymin -=  1.5 * yp;
		f->ymax -=  1.5 * yp;
	}
	else
	{
		f->ymin -= yp * 1.5;
		f->ymax -= yp * 1.5;
	}
	f->ymax = (f->ymax * f->zoom);
	f->ymin = (f->ymin * f->zoom);
	f->xmin = (f->xmin * f->zoom);
	f->xmax = (f->xmax * f->zoom);
	f->img = mlx_new_image(f->mlx, Y_LEN, X_LEN);
	f->h++;
	f->itteration++;
	ft_print_mande(f);
	return (x);
}

int	ft_dezoom(int x, int y, t_data *f)
{
	x = X_LEN / 3;
	y = Y_LEN / 3;
	mlx_destroy_image(f->mlx, f->img); 
	mlx_mouse_get_pos(f->mlx, f->win, &f->xp, &f->yp);
	f->ymax = f->ymax * 1.1;
	f->ymin = f->ymin * 1.1;
	f->xmin = f->xmin * 1.1;
	f->xmax = f->xmax * 1.1;
	f->img = mlx_new_image(f->mlx, Y_LEN, X_LEN);
	if (f->itteration > 50)
		f->itteration--;
	f->h--;
	ft_print_mande(f);
	return (x);
}
