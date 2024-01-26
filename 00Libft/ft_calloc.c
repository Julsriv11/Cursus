/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:43:24 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 11:34:37 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para asignar una cantidad de memoria dinámica en el tiempo de 
 * ejecución. La función toma dos argumentos, el número de elementos y el 
 * tamaño de cada elemento. A diferencia de malloc, inicializa la memoria a 0,
 * y no con datos no guardados previamente. Utiliza malloc para alocar memoria,
 * fx permitida. Primero comprueba que count y size son positivos, 
 * si no es así, solo asigna un byte de memoria para evitar  posibles 
 * problemas. Si son positivos, les asigna la memoria necesaria (count * size). 
 * Verifica si la asignación fue exitosa inicializando todos los bytes de 
 * memoria a 0, y si no, devuelve NULL. */

#include <stdlib.h>

void	ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)b;
	i = 0;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	x = (void *)malloc(count * size);
	if (!x)
		return (0);
	ft_memset(x, 0, count * size);
	return (x);
}
