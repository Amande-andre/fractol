/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 15:06:33 by anmande          ###   ########.fr       */
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

int	ft_conv(t_data *man, int x, int y)
{
	t_comp	z;
	t_comp	c;
	int		n;
	long	tmp;

	z.real = 0;
	z.unreal = 0;
	c.real = (man->left + x) * (man->x_len / X_LEN);
	c.unreal = (man->top + y) * (man->y_len / Y_LEN);
	n = 0;
	while ((z.real * z.real) + (z.unreal * z.unreal) <= 4 && n < INT_MAX)
	{
		tmp = 2 * z.real * z.unreal;
		z.real = (z.real * z.real) - (z.unreal * z.unreal) + c.real;
		z.unreal = tmp + c.unreal;
		n++;
		printf("1\n"); // Boucle infini ici!!!
		//my_mlx_pixel_put(man->img, man->x_len, man->y_len, 0x0000FF);
	}
	return (n);
}