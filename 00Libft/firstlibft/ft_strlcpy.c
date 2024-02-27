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

#include <stdio.h>
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

/*int	main()
{
	char	str[] = "Lyon king and bambi";
	char	dst[16];
	size_t	len;

	len = ft_strlcpy(dst, str, sizeof(dst));
	printf("Original: %zu\n", len);
	len = strlcpy(dst, str, sizeof(dst));
	printf("Manual: %zu\n",len);
	return (0);
}*/

/*int main()
{
	char	*one = "Esternocleidomastoideo";
	char	end[30];

	printf("%zu", ft_strlcpy(end, one, sizeof(end)));
	return 0;
}*/