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

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
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