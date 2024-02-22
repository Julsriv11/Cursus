/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:51:48 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/13 14:12:54 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A diferencia de strstr, esta función devuelve SÓLO la posición de inicio
 * de la primera coincidencia de la subcadena dentro de la cadena*/

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/*int main()
{
	const char	*str = "Wally is in Wallington";
	const char	*to_find = "Wllington";
	const char	*result;
	const char	*origin;

	result = ft_strnstr(str, to_find, 50);
	origin = strnstr(str, to_find, 50);
	if (result != NULL)
	{
		printf("He was found in %s.\n", result);
		printf("Original found in %s.\n", origin);
	}
	else
		printf("Not found\n");
	return (0);
}*/

int main()
{
	char	one[] = "roro";
	char	two[] = "Found roro in the whole world";

	printf("%s", ft_strnstr(two, one, 3));
	return 0;
}