/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:43:24 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 11:23:25 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	if (count > 0 && size > 0 && SIZE_MAX / size < count)
		return (NULL);
	x = (void *)malloc(count * size);
	if (!x)
		return (0);
	ft_memset(x, 0, count * size);
	return (x);
}

/*int main ()
{
	ft_calloc(1646151656164, 20849816189498);
	return 0;
}*/