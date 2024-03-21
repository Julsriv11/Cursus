/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:17:09 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/21 12:52:45 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(uintptr_t ptr)
{
	char	*base;
	int		amount;

	base = "0123456789abcdef";
	amount = 0;
	if (ptr < 16)
		amount += print_c(base[ptr]);
	else
	{
		amount += print_ptr(ptr / 16);
		amount += print_c(base[ptr % 16]);
	}
	return (amount);
}

int	print_num(int x)
{
	int		len;

	len = 0;
	if (x == -2147483648)
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

int	print_unsigned(unsigned int n)
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

int	print_hex(unsigned int hex, char *base)
{
	int	len;

	len = 0;
	if (hex < 16)
		len += print_c(base[hex]);
	else
	{
		len += print_hex(hex / 16, base);
		len += print_c(base[hex % 16]);
	}
	return (len);
}
