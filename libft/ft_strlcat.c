/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:46:45 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 12:43:03 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j])
		j++;
	while (src[len] && (i + len + 1) < size)
	{
		dst[i + len] = src[len];
		len++;
	}
	if (i != size)
		dst[i + len] = '\0';
	return (i + j);
}
