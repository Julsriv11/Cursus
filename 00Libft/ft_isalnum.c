/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:14:56 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 19:35:47 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*int main()
{
	int	x = 'J';

	if (ft_isalnum(x) != 0)
		printf("Verdadero %d", ft_isalnum(x));
	else
		printf("Falso %d", ft_isalnum(x));
	return 0;
}*/