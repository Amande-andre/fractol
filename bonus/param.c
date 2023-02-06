/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:23 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 10:51:12 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_param(t_data *f, char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ft_print_mande(f);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (ft_julia_param(f, av[2]));
	else
	{
		printf("You can us \"Mandelbrot\"as parameter\n");
		printf("You can us \"Julia\"as parameter\n");
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
