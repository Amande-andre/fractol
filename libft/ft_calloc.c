/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:37:06 by anmande           #+#    #+#             */
/*   Updated: 2022/05/30 14:34:24 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	s = (void *)malloc(sizeof(void) * (nmemb * size));
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
