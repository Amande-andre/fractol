/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:28 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 17:00:34 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_move(int key, t_data *f)
{
	float	deltax;
	float	deltay;

	deltax = f->xmax - f->xmin;
	deltay = f->ymax - f->ymin;
	if (key == PRESS_ARROW_RIGHT)
	{
		f->xmin -= deltax * 0.05;
		f->xmax -= deltax * 0.05;
	}
	else if (key == PRESS_ARROW_LEFT)
	{
		f->xmin += deltax * 0.05;
		f->xmax += deltax * 0.05;
	}
	else if (key == PRESS_ARROW_DOWN)
	{
		f->ymin += deltay * 0.05;
		f->ymax += deltay * 0.05;
	}
	else if (key == PRESS_ARROW_UP)
	{
		f->ymin -= deltay * 0.05;
		f->ymax -= deltay * 0.05;
	}
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, Y_LEN, X_LEN);
	ft_print_mande(f);

	return 0;
}

// int	ft_up(t_data *f)
// {
// 	printf("ok%f", man->delta);
// 	return 0;
// }