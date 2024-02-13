/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:18:27 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/13 14:19:07 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//comprueba si un int es un dígito
#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

/*int main()
{
	int	x = '7';

	if (ft_isdigit(x) != 0)
		printf("Verdadero es %d", ft_isdigit(x));
	else
		printf("Falso %d", ft_isdigit(x));
	return 0;
}*/