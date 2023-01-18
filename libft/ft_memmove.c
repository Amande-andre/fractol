/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:14:57 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 19:12:07 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = (char *)malloc((sizeof(char *) * ft_strlen(src)) + 1);
	if (!d)
		return (NULL);
	if (n == 0)
		d[n] = '\0';
	ft_memcpy(d, s, n);
	ft_memcpy(dest, d, n);
	free (d);
	return (dest);
}

/*
#include <stdlib.h>
#include <string.h>
int	main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest; 
	dest = src + 1;
	char *tmp = strdup(dest);
	char *tmp2 = strdup(dest);
	char *i = ft_memmove(tmp, src, 8);
	char *i2 = memmove(tmp2, src, 8);
	printf("ft_ %s | %ld\n", i, ft_strlen(i));
	printf("tru %s | %ld\n", i2, ft_strlen(i2));

	free (tmp);
	free (tmp2);
}
*/