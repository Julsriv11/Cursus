/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:17:09 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/19 16:35:29 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_ptr(uintptr_t ptr)
{
	char	*base;
	int		amount;

	base = "0123456789abcdef";	//representación de los dígitos hexadecimales
	amount = 0;	//cuenta los char que se escribirán
	if (ptr < 16)	//si el valor pasado es inferior a su base, es decir = 16, se esta tratando con un solo dígito hexadecimal
		amount += write(1, &base[ptr], 1);	//se escribe este dígito en la salida y el resultado se acumula en amount
	else	//si por el contrario es mayor a 16, se hará una llamada recursiva de la función para ir diviendo por 16
	{
		amount += print_ptr(ptr / 16);	//se imprimen en orden correcto <=> de + significativo a menos
		amount += write(1, &base[ptr % 16], 1);	//se escribe el resto de la división y también se acumula en amount
	}
	return (amount);
}

int print_num(int x)
{
    int		len;
	long	nb;
    
	nb = x;
	if (x < 0)
	{
		len += print_c('-');
		x = x * -1;
	}
	if (x < 10)
	{
		len += print_c(x + '0');
	}
	else
	{
		len += print_num(x / 10);
		len += print_num(x % 10);
	}
    return (len);
}

int     print_unsigned(unsigned int n);
int     print_hexadecimal(unsigned int hex, char *base);