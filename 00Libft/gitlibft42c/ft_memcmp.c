/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:48:26 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/08 12:27:00 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ptr_s1[i] != (unsigned char)ptr_s2[i])
			return ((int)(unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		i++;
	}
	return (0);
}

/*int	main()
{
	const char	str1[] = "Oslo que tal";
	const char	str2[] = "Osla que tal";
	int		x;
	int		y;

	x = ft_memcmp(str1, str2, 10);
	printf("R1 %d\n", x);
	y = memcmp(str1, str2, 10);
	printf("R2 %d\n", y);
	return (0);
}*/
