/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:25 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/13 12:24:34 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El primer if verifica si hay superposición de memoria, que sí la hay, la copia
 * comienza por el final para evitar sobreescribir datoas antes de que se 
 * copien. Esta condición verifica si dst está después de src pero antes del 
 * final de src + len. Si esta condición es verdadera, significa que hay 
 * una superposición.*/

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dst = dst;
	ptr_src = src;
	if (dst > src && dst < src + len)
	{
		i = len;
		while (i > 0)
		{
			ptr_dst[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
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
	char	str[] = "It`s just a copy";
	char	dest[];

	ft_memmove(dest, str, 4);
	printf("What it is? %s\n", dest);
	memmove(dest, str, 5);
	printf("The original %s \n", dest);
	return(0);
}*/
