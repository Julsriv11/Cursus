/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:21:40 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/11 18:30:05 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Lowercase char a-z 97-122
//Uppercase char A-Z 65-90

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 65 && c <= 90)
		return (c - 32);
	return (c);
}

/*int	main()
{
	int	c;

	c = 'A';
	printf(" %c \n", ft_toupper(c));
	return (0);
}*/
