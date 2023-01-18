/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:44:40 by anmande           #+#    #+#             */
/*   Updated: 2022/05/24 14:53:22 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (str1[i] == '\0' || str2[i] == '\0')
		return (str1[i] - str2[i]);
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i + 1] == '\0' || str2[i + 1] == '\0')
			return (str1[i + 1] - str2[i + 1]);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char s1[] = "1234";
// 	char s2[] = "1235";
// 	printf("%d\n", ft_strncmp(s1, s2, 4));
// 	printf("%d\n", strncmp(s1, s2, 4));
// }