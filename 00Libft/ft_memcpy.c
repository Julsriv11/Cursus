/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:15 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 11:34:55 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	if (!dst || !src)
		return (dst);
	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	i = 0;
	while (i < n) // no inicializa ningún iterador (n > 0)
	{
		ptr_dst[i] = ptr_src[i]; // sería ptr_dst++ = ptr_src++; y n--;
	}
	return (ptr_dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (n--)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}