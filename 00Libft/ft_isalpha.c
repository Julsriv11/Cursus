/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:17:05 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 19:36:25 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//comprueba si un int es alfabético o no
#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	else
		return (0);
}

/*int main()
{
	int	x = '7';

	if (ft_isalpha(x) != 0)
		printf("Verdadero es %d", ft_isalpha(x));
	else
		printf("Falso %d", ft_isalpha(x));
	return 0;
}*/