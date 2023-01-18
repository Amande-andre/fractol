/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:02:39 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 19:29:22 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char *tmpmemset = NULL;
// 	//char *strmemset = strdup(tmpmemset);
// 	char *imemset = ft_memset(tmpmemset, 'p', 5);
// 	printf("%s\n", imemset);
// 	//char *i2memset = memset(tmpmemset, 't', 5);
// 	//printf("%s\n", i2memset);
// }