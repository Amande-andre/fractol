/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:28 by anmande           #+#    #+#             */
/*   Updated: 2023/01/30 18:39:17 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_move(int key, t_data *man)
{
	float	deltax;
	float	deltay;

	deltax = man->xmax - man->xmin;
	deltay = man->ymax - man->ymin;
	if (key == PRESS_ARROW_RIGHT)
	{
		man->xmin -= deltax * 0.05;
		man->xmax -= deltax * 0.05;
	}
	else if (key == PRESS_ARROW_LEFT)
	{
		man->xmin += deltax * 0.05;
		man->xmax += deltax * 0.05;
	}
	else if (key == PRESS_ARROW_DOWN)
	{
		man->ymin += deltay * 0.05;
		man->ymax += deltay * 0.05;
	}
	else if (key == PRESS_ARROW_UP)
	{
		man->ymin -= deltay * 0.05;
		man->ymax -= deltay * 0.05;
	}
	else
		return (0);

	mlx_destroy_image(man->mlx, man->img);
	//mlx_clear_window(man->mlx, man->win);
	man->img = mlx_new_image(man->mlx, Y_LEN, X_LEN);

	ft_print_mande(man, 0x0000FF);

	return 0;
}

// int	ft_up(t_data *man)
// {
// 	printf("ok%f", man->delta);
// 	return 0;
// }