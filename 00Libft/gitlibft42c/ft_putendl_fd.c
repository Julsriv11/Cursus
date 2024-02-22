/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:58:59 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/14 20:54:49 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/*int	main(void)
{
	char *s = "Probando esto de los fd";
	int fd = 1;

	ft_putendl_fd(s, fd);

	return (0);
}*/