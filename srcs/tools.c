/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/25 19:30:35 by anmande          ###   ########.fr       */
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
int	ft_conv(t_data *man, int i, int j)
{
	t_comp	z;
	t_comp	c;
	int		n;
	t_comp	tmp;
	n = 0;
	z.re = 0;
	z.im = 0;
	//ici me permet de mettre mom pixel dans un plan orthonorme
	c.re = man->xmin + i * (man->xmax - man->xmin) / X_LEN;
	c.im = man->ymin + j * (man->ymax - man->ymin) / Y_LEN;
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
	else if (code == 5 || code == 2)
	{
		ft_dezoom(x, y, man);
	}
	return (0);
}
int	ft_zoom(int x, int y, t_data *man)
{
	//printf("y===%d\nx===%d\n", man->yp, man->xp);
	// man->yp = (double)man->y;
	// man->xp = (double)man->x;
	// man->yp = (double)y;
	// man->xp = (double)x;
	x = y;
	
	mlx_destroy_image(man->mlx, man->img); 
	printf("calcul tres savant%f\n\n", (man->yp / Y_LEN) * (man->ymax - man->ymin) * 0.3);
	man->ymax += (man->yp / Y_LEN) * (man->ymax - man->ymin - 0.1) * 0.3;
	man->ymin -=  (man->yp / Y_LEN) * (man->ymax - man->ymin - 0.1) * 0.3;
	man->xmin -=  (man->xp / X_LEN) * (man->xmax - man->xmin - 0.1) * 0.3;
	man->xmax +=  (man->xp / X_LEN) * (man->xmax - man->xmin - 0.1) * 0.3;	
	man->img = mlx_new_image(man->mlx, Y_LEN, X_LEN);
	printf("ymax%f\nxmax%f\nxmin%f\nymin%f\n", man->ymax, man->ymin, man->xmax, man->xmin);
	ft_print_mande(man, 0x0000FF);
	man->itteration++;
	return (x);
}

int	ft_dezoom(int x, int y, t_data *man)
{
	man->yp = (double)y;
	man->xp = (double)x;

	man->ymax += (man->yp / Y_LEN) * (man->ymax - man->ymin) * 0.1;
	man->ymin -=  (man->yp / Y_LEN) * (man->ymax - man->ymin) * 0.1;
	man->xmin -=  (man->xp / X_LEN) * (man->xmax - man->xmin) * 0.1;
	man->xmax +=  (man->xp / X_LEN) * (man->xmax - man->xmin) * 0.1;
	return (0);
}
