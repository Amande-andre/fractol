/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/30 18:57:15 by anmande          ###   ########.fr       */
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

int	ft_close_win(int key, t_data *man)
{
	if (key == XK_Escape || key == 17)
    {
		mlx_destroy_window(man->mlx, man->win);
		exit (0);
	}
	return (0);
}

int	ft_close_win2(t_data *man)
{
	mlx_destroy_window(man->mlx, man->win);
	exit (0);
}
int	ft_conv(t_data *man, double i, double j)
{
	t_comp	z;
	t_comp	c;
	int		n;
	t_comp	tmp;
	n = 0;
	z.re = 0;
	z.im = 0;

	// if (man->zoom == 1)
	// {	
	
		c.re = man->xmin + i * (man->xmax - man->xmin) / X_LEN;
	 	c.im = man->ymin + j * (man->ymax - man->ymin) / Y_LEN;
		// c.re = man->xmin + i * (double)man->xp / X_LEN;
		// c.im = man->ymin + j * (double)man->yp / Y_LEN;
	//}
	// else
	// {
	// 	c.re = man->xmin * 0.1 + i * (man->xmax - man->xmin) / X_LEN;
	// 	c.im = man->ymin * 0.1 + j * (man->ymax - man->ymin) / Y_LEN;
	// }
	
	n = 0;
	while ((z.re * z.re + z.im * z.im) <= 2 && n < man->itteration)
	{
		tmp.im = 2 * z.re * z.im + c.im;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		z.re = tmp.re;
		z.im = tmp.im;
		n++;
	}
	return (n);
}

int	ft_mouse_hook(int code, int x, int y, t_data *man)
{
	if (code == 4 || code == 1)
		ft_zoom(x, y, man);
	else if ((code == 5 || code == 2) && man->h >= 0)
		ft_dezoom(x, y, man);
	// else if (code == PRESS_ARROW_DOWN)
	// 	ft_down();
	// else if (code == PRESS_ARROW_LEFT)
	// 	ft_left();
	// else if (code == PRESS_ARROW_RIGHT)
	// 	ft_right();
	return (1);
}

int	ft_zoom(int x, int y, t_data *man)
{
	float	xdelta;
	float	ydelta;
	float	xp;
	float	yp;
	x = X_LEN / 3;
	y = Y_LEN / 3;
	xdelta = (man->xmax - man->xmin);
	ydelta = (man->ymax - man->ymin);
	//xp = 0;
	mlx_destroy_image(man->mlx, man->img);
	mlx_mouse_get_pos(man->mlx, man->win, &man->xp, &man->yp);
	//printf("xminBC=%f\nyminBC=%f\ndelta==%f\nposi==%f\n", man->xmin, man->ymin, man->delta, xp);
	//xp = man->xp / X_LEN + (man->xmax - man->xmin) + man->xmin;
	//yp = man->yp / Y_LEN + (man->ymax - man->ymin) + man->ymin;
	//printf("55\nxminBC=%f\nxmaxBC=%f\ndelta==%f\nxposi==%f\n", man->xmin, man->xmax, xdelta, xp);
	xp = ((double)man->xp / (X_LEN / xdelta)) + man->xmin;
	yp = (((double)man->yp / (Y_LEN / ydelta)) - man->ymax);
	printf("xp==%f\nyp==%f\n", xp, yp);
	if (xp > 0)
	{
		man->xmin -= xdelta * 0.05;
		man->xmax -= xdelta * 0.05;
	}
	else
	{
		man->xmin += xdelta * 0.05;
		man->xmax += xdelta * 0.05;
	}
	if (yp > 0)
	{
		man->ymin += ydelta * 0.05;
		man->ymax += ydelta * 0.05;
	}
	else
	{
		man->ymin -= ydelta * 0.05;
		man->ymax -= ydelta * 0.05;
	}

	
	
	// man->ymax -= ((ydelta) + yp);
	// man->ymin -= ((ydelta) - yp);
	// man->xmin -= ((xdelta) - xp);
	// man->xmax -= ((xdelta) + xp);
	// man->ymax = (man->ymax * man->zoom);
	// man->ymin = (man->ymin * man->zoom);
	// man->xmin = (man->xmin * man->zoom);
	// man->xmax = (man->xmax * man->zoom);
	//printf("2\nxminBC=%f\nxmaxBC=%f\ndelta==%f\nxposi==%f\n", man->xmin, man->xmax, xdelta, xp);

	man->img = mlx_new_image(man->mlx, Y_LEN, X_LEN);
	//printf("xminAC=%f\nyminAC=%f\n", man->xmin, man->ymin);
	man->h++;
	man->itteration++;
	ft_print_mande(man, 0x0000FF);
	return (x);
}

int	ft_dezoom(int x, int y, t_data *man)
{
	x = X_LEN / 3;
	y = Y_LEN / 3;
	mlx_destroy_image(man->mlx, man->img); 
	mlx_mouse_get_pos(man->mlx, man->win, &man->xp, &man->yp);
	man->ymax = man->ymax * 1.1;
	man->ymin = man->ymin * 1.1;
	man->xmin = man->xmin * 1.1;
	man->xmax = man->xmax * 1.1;
	man->img = mlx_new_image(man->mlx, Y_LEN, X_LEN);
	//printf("xp=%d\nyp=%d\n", man->xp, man->yp);
	if (man->itteration > 50)
		man->itteration--;
	man->h--;
	ft_print_mande(man, 0x0000FF);
	return (x);
}
