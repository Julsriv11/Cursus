/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:34 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/27 16:43:05 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//fx que te lea nueva linea
//fx que te despeje o limpie donde acumulas

static 	ft_freedom(char **str)
{
	free (*str);
}

char    *get_next_line(int fd)
{
    //read(int fd, void *buf, size_t buff_size);

    close(fd);
}

