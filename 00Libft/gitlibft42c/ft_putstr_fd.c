/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:58:25 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/14 20:55:15 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	else
		write(fd, s, ft_strlen(s));
}

/*#include <fcntl.h>

int main(void)
{
	char *s = "Probando esto de los fd";
	int fd;

	fd = open("prueba.txt", O_WRONLY);

	ft_putstr_fd(s, fd);
}*/