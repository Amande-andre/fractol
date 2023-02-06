/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:28 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 10:47:49 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_move(int key, t_data *f)
{
	float	deltax;
	float	deltay;

	deltax = f->xmax - f->xmin;
	deltay = f->ymax - f->ymin;
	ft_move_man(key, f, deltax, deltay);
	return (0);
}

int	ft_move_man(int key, t_data *f, int deltax, int deltay)
{
	if (key == PRESS_ARROW_LEFT)
	{
		f->xmin -= deltax * 0.05;
		f->xmax -= deltax * 0.05;
	}
	else if (key == PRESS_ARROW_RIGHT)
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
	ft_print(f);
	return (0);
}
