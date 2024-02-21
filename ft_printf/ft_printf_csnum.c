/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:47:02 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/17 16:48:16 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//funciones: imprime puntero, imprime string, imprime int, imprime numero
//de cualquier tipo unsigned int con base, char, size.

#include "ft_printf.h"
size_t	own_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int print_str(char *s)
{
    int len;

    len = 0;
    if (*s != '\0')
    {
        len = own_strlen(s);
        write(1, s, len);
    }   return (len);
    write(1, "(null)", 6);
    return (6);
}

int print_c(char c)
{
    write(1, &c, 1);
    return (1);
}

int print_num(int x)
{
    int len;
    char *num;

    len = 0;
    num = ft_itoa(x);
    len = print_str(num);
    free(num);
    return (len);
}