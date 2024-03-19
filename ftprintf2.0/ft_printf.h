/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:54:24 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/19 16:35:11 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> //Write
# include <stdlib.h> //Malloc
# include <stdarg.h> //Variables variádicas
# include <stdio.h> //Todo
# include <stdint.h> //Manejar dato uintptr_t
# include <limits.h> //INT_MAX

int     print_str(char *s);
int     print_c(char c);
int     print_num(int x);
int     print_ptr(uintptr_t ptr);
int     print_unsigned(unsigned int n);
int     print_hexadecimal(unsigned int hex, char *base);
int     ft_parameters(va_list args, int printlen, const char s);
int	    ft_printf(char const *s, ...);

#endif
