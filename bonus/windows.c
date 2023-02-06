/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:57 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 10:51:33 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_close_win(int key, t_data *f)
{
	if (key == XK_Escape || key == 17)
	{
		mlx_destroy_window(f->mlx, f->win);
		mlx_clear_window(f->mlx, f->win);
		exit (0);
	}
	return (0);
}

int	ft_close_win2(t_data *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_clear_window(f->mlx, f->win);
	exit (0);
}
