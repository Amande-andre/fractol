/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:57 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 14:17:59 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_inc/fractol_bonus.h"

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
		mlx_loop_end(f->mlx);
		if (f->img)
			mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		exit (0);
	}
	return (0);
}

int	ft_close_win2(t_data *f)
{
	mlx_loop_end(f->mlx);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit (0);
}
