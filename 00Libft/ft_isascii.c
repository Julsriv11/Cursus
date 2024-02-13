/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:11:40 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/13 14:18:17 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int main()
{
	int	x = '7';

	if (ft_isascii(x) != 0)
		printf("Verdadero es %d", ft_isascii(x));
	else
		printf("Falso %d", ft_isascii(x));
	return 0;
}*/