/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:54:24 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/21 10:40:18 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int	print_str(char *s);
int	print_c(char c);
int	print_num(int x);
int	print_ptr(uintptr_t ptr);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int hex, char *base);
int	ft_parameters(va_list args, int printlen, const char s);
int	ft_printf(char const *s, ...);

#endif
