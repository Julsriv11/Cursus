/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:12:15 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/08 19:28:51 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

//void *memcpy(void *dest, const void *src, size_t n)
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_src = src;
	ptr_dst = dst;
	i = 0;
	if (dst == NULL || src == NULL)
		return(NULL);
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
