/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:44 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 15:21:56 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > i)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>
int main()
{
	char	*one = "Esternocleidomastoideo";
	char	end[30];
	char	*one2 = "Esternocleidomastoideo";
	char	end2[30];

	printf("FT: %zu, %s\n", ft_strlcpy(end, one, sizeof(end)), end);
	printf("OG: %zu, %s\n", strlcpy(end2, one2, sizeof(end2)), end2);
	return 0;
}