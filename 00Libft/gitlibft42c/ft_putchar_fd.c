/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:57:38 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 14:58:10 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("prueba.txt", O_WRONLY);

	ft_putchar_fd('J', fd);
}
Para realizar esta función, se crea una archivo.txt en la carpeta. Se escribe este
main, se compila y se ejecuta. Tras realizar esto, al abrir ell archivo se habrá
escrito la J.
*/