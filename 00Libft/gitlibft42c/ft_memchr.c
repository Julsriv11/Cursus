/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:43:14 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/11 18:48:04 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*int main()
{
    const char *str = "He is in London";
    const void *found;

    found = ft_memchr(str, 'L', strlen(str));
    printf("Where is Garbi? %p \n", found);
    found = memchr(str, 'L', strlen(str));
    printf("Original one adress: %p \n", found);
    return 0;
}*/