/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:25 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/08 12:54:13 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El primer if verifica si hay superposición de memoria, que sí la hay, la copia
 * comienza por el final para evitar sobreescribir datos antes de que se 
 * copien. Esta condición verifica si dst está después de src pero antes del 
 * final de src + len. Si esta condición es verdadera, significa que hay 
 * una superposición.*/

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	i = 0;
	if (ptr_dst > ptr_src)
	{
		while (len-- > 0)
			ptr_dst[len] = ptr_src[len];
	}
	else
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}

/*int main()
{
	char	str[] = "Esto es una prueba";
	char	dest[50];

	ft_memmove(dest, str, 4);
	printf("What it is? %s\n", dest);
	memmove(dest, str, 4);
	printf("The original %s \n", dest);
	return(0);
}*/
