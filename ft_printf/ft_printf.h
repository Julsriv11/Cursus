/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:54:24 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/17 16:54:27 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

size_t	own_strlen(const char *str);
int     print_str(char *s);
int     print_c(char c);
int     print_num(int x);
int     print_ptr(unsigned long long ptr);
int     print_unsigned(unsigned int n);
int     ft_parameters(const char *s, va_list args);
int	    ft_printf(char const *s, ...);

#endif
