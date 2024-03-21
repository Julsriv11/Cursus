/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:42:30 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/21 11:24:48 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len] != '\0')
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	 ft_parameters(va_list args, int printlen, const char s)
{
	if (s == 'c')
		printlen += print_c(va_arg(args, int));
	else if (s == 'i' || s == 'd')
		printlen += print_num(va_arg(args, int));
	else if (s == 's')
		printlen += print_str(va_arg(args, char *));
	else if (s == 'p')
	{
		write(1, "0x", 2);
		printlen += print_ptr(va_arg(args, uintptr_t)) + 2;
	}
	else if (s == 'u')
		printlen += print_unsigned(va_arg(args, unsigned int));
	else if (s == 'x')
		printlen += print_hexadecimal(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		printlen += print_hexadecimal(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (s == '%')
		printlen += print_c('%');
	return (printlen);
}
//me printea la longitud que reciba

int	ft_printf(char const *s, ...) 
{
	size_t	print;
	va_list	args;
	int		i;

	print = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			print = ft_parameters(args, print, s[i]);
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (0);
		else 
			print = print + print_c(s[i]);
		i++;
	}
	va_end(args);
	return (print);
}
