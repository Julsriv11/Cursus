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

#include "libft.h"

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
	char str[] = "Es muuy chuli";
	char other[30];

	printf("Mi copia %s", ft_memmove(other, str, ft_strlen(str)));
	return 0;
}*/