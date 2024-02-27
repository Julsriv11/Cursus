/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:17:02 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/08 15:26:33 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 040 && c <= 0176);
}

/*int main()
{
	int	x = '7';

	if (ft_isprint(x) != 0)
		printf("Verdadero es %d", ft_isprint(x));
	else
		printf("Falso %d", ft_isprint(x));
	return 0;
}*/