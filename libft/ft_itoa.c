/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:14:10 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 18:04:40 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(long int n, long int size)
{
	long int	nb;
	char		*str;

	str = ft_calloc(sizeof(char), size + 2);
	if (!str)
		return (NULL);
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb >= 10)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	str[size] = nb + '0';
	if (n < 0 && nb < 10)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*a;
	long int	i;
	long int	nb;
	long int	n2;

	i = 0;
	n2 = n;
	if (n2 < 0)
	{
		nb = n2 * -1;
		i++;
	}
	else
		nb = n2;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	a = (ft_putnbr(n, i));
	if (!a)
		return (NULL);
	return (a);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	int	n = ft_atoi(av[1]);
// 	printf("%s\n", ft_itoa(n));
// }
