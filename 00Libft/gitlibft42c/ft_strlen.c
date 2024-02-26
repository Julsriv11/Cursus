/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:29:08 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 14:59:48 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/* Comprobar que exista el parámetro que recibimos
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	//
	if (s == NULL)
		return (len);
	//
	while (s[len] != '\0')
		len++;
	return (len);
}*/