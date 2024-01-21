/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:29:05 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 19:24:03 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>*/

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//#endif
