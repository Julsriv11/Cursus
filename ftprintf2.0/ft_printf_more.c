/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliaariasiniesta <juliaariasiniesta@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:17:09 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/20 15:02:55 by juliaariasi      ###   ########.fr       */
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
		amount += print_c(base[ptr]);	//se escribe este dígito en la salida y el resultado se acumula en amount
	else	//si por el contrario es mayor a 16, se hará una llamada recursiva de la función para ir diviendo por 16
	{
		amount += print_ptr(ptr / 16);	//se imprimen en orden correcto <=> de + significativo a menos
		amount += print_c(base[ptr % 16]);	//se escribe el resto de la división y también se acumula en amount
	}
	return (amount);
}

int print_num(int x)
{
    int		len;
	long	nb;
    
	nb = x;
	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (x < 0)
	{
		len += print_c('-');
		x = x * -1;
	}
	if (x < 10)
		len += print_c(x + '0');
	else
	{
		len += print_num(x / 10);
		len += print_c(x % 10 + '0');
	}
    return (len);
}

int     print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += print_c(n + '0');
	else
	{
		len += print_unsigned(n / 10);
		len += print_c(n % 10 + '0');
	}
	return (len);
}

int     print_hexadecimal(unsigned int hex, char *base)
{
	int	len;

	len = 0;
	if (hex < 16)
		len += print_c(base[hex]);
	else
	{
		len += print_hexadecimal(hex / 16, base);
		len += print_c(base[hex % 16]);
	}
	return (len);
}