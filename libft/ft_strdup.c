/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:51:09 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 18:26:08 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	if (s == NULL)
		return (NULL);
	cpy = (char *)malloc((ft_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	if (cpy)
		ft_memcpy(cpy, s, (ft_strlen(s) + 1));
	return (cpy);
}

/*
#include <stdio.h>
int main()
{
	char	*str = "ceci est un test";
	char	*ret = ft_strdup(str);
	printf("%lu", sizeof(char));
	free(ret);
}
*/