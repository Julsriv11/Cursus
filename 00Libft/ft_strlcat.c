/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:35 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/09 18:54:54 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lon_dst;
	size_t	i;

	lon_dst = 0;
	while (dstsize > lon_dst && dst[lon_dst] != '\0')
		lon_dst++;
	i = 0;
	while (dstsize > lon_dst + i + 1 && src[i] != '\0')
	{
		dst[lon_dst + i] = src [i];
		i++;
	}
	if (dstsize > lon_dst)
		dst[lon_dst + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (lon_dst + i);
}

/*int	main(void)
{
	char	src[9] = "pressure";
	char	dest[6] = "Blood";
	size_t	lon;

	lon = ft_strlcat(dest, src, sizeof(dest));
	printf("Cadena completa: %s \n", dest);
	printf("Longitud de cadena: %zu \n", lon);
	return (0);
}*/
