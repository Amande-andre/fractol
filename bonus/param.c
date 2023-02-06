/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:23 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 14:17:47 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_inc/fractol_bonus.h"

int	ft_param(t_data *f, char **av, int ac)
{
	if (ac == 1)
	{
		write(1, "You can us \"Mandelbrot\"as parameter\n", 37);
		write(1, "You can us \"Julia\"as parameter\n", 32);
		return (1);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ft_print_mande(f);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (ft_julia_param(f, av[2]));
	else
	{
		write(1, "You can us \"Mandelbrot\"as parameter\n", 37);
		write(1, "You can us \"Julia\"as parameter\n", 32);
		return (1);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1[i] == '\0' || str2[i] == '\0')
		return (str1[i] - str2[i]);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i + 1] == '\0' || str2[i + 1] == '\0')
			return (str1[i + 1] - str2[i + 1]);
		i++;
	}
	return (0);
}
