/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:19:57 by anmande           #+#    #+#             */
/*   Updated: 2022/05/10 10:17:44 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int main()
{
		printf("\nft_bzero\n");
	char tmpbz[11] = "0123456789";
	char *ibz = strdup(tmpbz);
	char *i2bz = strdup(tmpbz);
	ft_bzero(ibz, 5);
	bzero(i2bz, 5);
	printf("%s\n%s\n", ibz, i2bz);
}
*/