/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:30:21 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/11 18:31:52 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//lowercase char 97-122
//uppercase char 65-90
/*El motivo de tener dos declaraciones return es el siguiente:
Si la condición if es verdadera (es decir, c es una letra mayúscula), 
se ejecuta el primer return para devolver el valor convertido.
Si la condición if es falsa (es decir, c no es una letra mayúscula), 
se omite el primer return y se ejecuta el segundo return, devolviendo el valor 
original de c sin cambios.*/

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*int main()
{
    int x;

    x = '#';
    printf("%c \n", ft_tolower(x));
    return 0;
}*/
