/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:32:37 by anmande           #+#    #+#             */
/*   Updated: 2023/02/04 17:48:23 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_julia_loop(t_data *f)
{
	f->c.re = -1;
	while (f->c.re < 1)
	{
		f->c.re += 0.2;
		while (f->c.im < 1)
		{
			f->c.im += 0.2;
			ft_print_julia(f, f->color);
		}
		f->c.im = -1.1;
	}
	return (0);
}

	// if (xp > 0)
	// {
	// 	f->xmin -= xdelta * 0.05 + xp;
	// 	f->xmax -= xdelta * 0.05 + xp;
	// }
	// else
	// {
	// 	f->xmin += xp * 0.5 * -1;
	// 	f->xmax += xp * 0.5 * -1;
	// }
	// if (yp >= 0)
	// {
	// 	f->ymin -=  1.5 * yp;
	// 	f->ymax -=  1.5 * yp;
	// }
	// else
	// {
	// 	f->ymin -= yp * 1.5;
	// 	f->ymax -= yp * 1.5;
	// }