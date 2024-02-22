/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:55:47 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 13:47:18 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		ptr[i++] = 0;
}

/*int main()/
{
    char str[] = "xxx rules";

    printf("%s\n", ft_bzero(str, 3));
    printf("%s\n", bzero(str, 3));
    return (0);
}*/
