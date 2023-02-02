/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:23 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 18:17:39 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_param(t_data *f, char *av)
{
	if (ft_strncmp(av, "Mandelbrot", 10) == 0)
		ft_print_mande(f);
	else if (ft_strncmp(av, "Julia", 10) == 0)
		ft_print_julia(f);
	else
	{
		printf("You can us \"Mandelbrot\"as parameter\n");
		printf("You can us \"Julia\"as parameter\n");
		return (0);
	}
	return (1);
}