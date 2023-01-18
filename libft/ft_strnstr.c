/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:57:46 by anmande           #+#    #+#             */
/*   Updated: 2022/05/12 14:14:23 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (little[i] == '\0')
		return (b);
	while (b[i])
	{
		j = 0;
		while (b[i + j] == l[j] && b[j] && l[j] && i + j < len)
		{
			j++;
			if (l[j] == '\0')
			{
				return (b + i);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
	const char	*big = "lorem ipsum dolor sit amet";
	const char	*little = "dolor";
	size_t	len = 15;
	printf("%s\n", ft_strnstr(big, little, len));
	printf("%s\n", strnstr(big, little, len));
	return (0);
}
*/
