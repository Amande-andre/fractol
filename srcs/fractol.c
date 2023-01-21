/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:37 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 12:44:09 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	t_data	man;
	int		color;

	// int x = 1;
	// int y = 1;
	color = 0x99FFFF;
	man.mlx = mlx_init();
	man.win = mlx_new_window(man.mlx, 1920, 1080, "test");
	man.img = mlx_new_image(man.mlx, 1920, 1080);
	man.addr = mlx_get_data_addr(man.img, &man.bits_per_pixel, &man.line_length, &man.endian);
	mlx_hook(man.win, 17, 0, ft_close_win, &man);
	mlx_loop(man.mlx);
	return (0);
}