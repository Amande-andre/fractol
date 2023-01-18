/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:08:49 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 18:49:40 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (void *)s;
	c = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	if (c > 256)
		c %= 256;
	while (i < n)
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char s[7] = "012345";
// 	printf("%s\n", (char *)ft_memchr(s, '2', 3));
// 	printf("%s\n", (char *)memchr(s, '2', 3));
// }