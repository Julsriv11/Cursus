/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:42:30 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/17 16:48:47 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//función strlen para este proyecto
//función que chequea lo que entra, si está vacía o no
//función que escribe lo que lee según encuentra un % o no
//función asigne número a tipo de argumento

int  ft_parameters(const char *s, va_list args)
{
    int	printlen;

	printlen = 0;
	if (*s == 'c')
        printlen += print_c(va_arg(args, int));
    else if (*s == 'i' || *s == 'd')
        printlen += print_num(va_arg(args, int));
    else if (*s == 's')
        printlen += print_str(va_arg(args, char *));
    else if (*s == 'p')
		printlen += print_ptr(va_arg(args, unsigned long long));
    else if (*s == 'u')
		printlen += print_unsigned(va_arg(args, unsigned int));
    else if (*s == 'x' || *s == 'X')
		printlen += print_hex(va_arg(args, unsigned int));
    else if (*s == '%')
	{
		write(1, '%', 1);
		return (1);
	}	
    return (printlen);
}
int	ft_printf(char const *s, ...) //me printea la longitud que reciba
{
	size_t	print;
	va_list	args;

	print = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s != '%' && *(s + 1) != '\0')
		{
			print += ft_parameters(s, args);
			s++;
		}
		else
		{
			write(1, s, 1);
			print++;
		}
		s++;
	}
	va_end(args);
	return (print);
}

/*int ft_printf(char const (*s, ...)
{
    inicia iterando la frase hasta que encuentre el símbolo %.
    Cuando encuentra % para de escribir y mira una posición más, 
    donde nos indica qué tipo de parámetro le estamos pasando.
    Una vez hayamos "escrito" nuestra string utilizando putstr y 
    contando el tamaño que tiene (para añadir más adelante), volvemos
    a la string principal y sigue imprimiendo hasta que vuelva a
    encontrar el %.
    
	int     i; //iterador para leer la frase
	int     j; //otro iterador para sumar lo que voy leyendo con %
	char    *str; //la frase a escribir
	va_list args; //argumentos que le vaya a pasar

	i = 0;
	j = 0;
	str = (char *(*s;
	va_start(args,(*s);
	while (str[i])
	{
    	if (str[i] != '%')
        	j = j + ft_putchar(str[i]);
    	else if (str[i] == '%')
    	{
        	j = ft_parameters(args, j, &str[i]);
        	i++;
    	}
    	i++;
	}
	va_end(args);
	return (j);
}*/
