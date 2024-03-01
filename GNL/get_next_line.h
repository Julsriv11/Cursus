/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliaariasiniesta <juliaariasiniesta@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:25:19 by jarias-i          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/29 19:17:23 by jarias-i         ###   ########.fr       */
=======
/*   Updated: 2024/03/01 19:28:14 by juliaariasi      ###   ########.fr       */
>>>>>>> 75084f4 (.h)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *get_each_lines(char *reach_lines);
char    *get_buf(char *reach_lines, int fd);
char    *get_next_line(int fd);

#endif