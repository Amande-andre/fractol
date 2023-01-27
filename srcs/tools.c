/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/27 21:02:58 by anmande          ###   ########.fr       */
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
	else if ((code == 5 || code == 2))
		ft_dezoom(x, y, man);
	else if (code == PRESS_ARROW_UP)
		ft_up(man);
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
	x = X_LEN / 3;
	y = Y_LEN / 3;
	man->delta = (man->xmax - man->xmin);
	mlx_destroy_image(man->mlx, man->img); 
	mlx_mouse_get_pos(man->mlx, man->win, &man->xp, &man->yp);
	printf("xminBC=%f\nyminBC=%f\ndelta==%f\nposi==%f\n", man->xmin, man->ymin, man->delta, (double)man->xp / X_LEN);
	man->xmin = (((double)man->xp * man->delta) / X_LEN) - man->delta;
	man->ymin = ((double)man->yp / Y_LEN) - man->delta;
	man->xmax = man->delta - ((double)man->xp / X_LEN);
	man->ymax = man->delta - ((double)man->yp / Y_LEN);
	// man->ymax = (man->ymax * man->zoom);
	// man->ymin = (man->ymin * man->zoom);
	// man->xmin = (man->xmin * man->zoom);
	// man->xmax = (man->xmax * man->zoom);

	man->img = mlx_new_image(man->mlx, Y_LEN, X_LEN);
	printf("xminAC=%f\nyminAC=%f\n", man->xmin, man->ymin);
	//man->zoom++;
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
	if (man->zoom > 1)
		man->itteration--;
	//man->zoom--;
	ft_print_mande(man, 0x0000FF);
	return (x);
}
