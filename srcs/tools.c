/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:30 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 13:10:48 by anmande          ###   ########.fr       */
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