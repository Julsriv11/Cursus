/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliaariasiniesta <juliaariasiniesta@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:55:26 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/09 12:41:38 by juliaariasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*to_the_endline(char *static_lines)
{
	int		i;
	int		j;
	char	*x;

	i = 0;
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
		i++;
	if (static_lines[i] == '\0')
    {
		free(static_lines);
		return (NULL);
    }
	x = (char *)malloc((ft_strlen(static_lines) - (i + 1) + 1) * sizeof(char));
	if (x == NULL)
	{
		free(static_lines);
		return (NULL);
	}
	i++;
	j = 0;
	while (static_lines[i] != '\0')
		x[j++] = static_lines[i++];
	x[j] = '\0';
	free(static_lines);
	return (x);
}

char	*full_line(char *static_lines)
{
	char	*line_completed;
	int		i;
	int		j;

	i = 0;
	if (!static_lines[i])
		return (NULL);
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
		i++;
	if (static_lines[i] == '\0')
		line_completed = malloc((i + 1) * sizeof(char));
	else
		line_completed = malloc((i + 2) * sizeof(char));
	if (line_completed == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
		line_completed[j++] = static_lines[i++];
	if (static_lines[i] == '\n')
		line_completed[j++] = static_lines[i++];
	line_completed[j] = '\0';
	return (line_completed);
}

char	*read_file(char *static_lines, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(static_lines, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); 
		if (bytes_read == -1)
		{
			free(static_lines);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		static_lines = ft_strjoin(static_lines, buffer);
	}
	free(buffer);
    return (static_lines);
}

char	*get_next_line(int fd)
{
	static char	*static_lines[MAX_FD]; //se transforma esta variable en un array de char con el máximo fd que sea capaz de gestionar
	char		*result;				// el ordenador

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_lines[fd] = read_file(static_lines[fd], fd);	//Se especifica que fd está leyendo para que no se sobreescriban otros fd
	if (static_lines[fd] == NULL)
		return (NULL);
	result = full_line(static_lines[fd]);
	static_lines[fd] = to_the_endline(static_lines[fd]);
	return (result);
}

// void ft_leaks()
// {
// 	system("leaks -q a.out");
// }

int main(void)
{
    int     fd1 = open("bonus1.txt", O_RDONLY);
	int     fd2 = open("bonus2.txt", O_RDONLY);
	int     fd3 = open("bonus3.txt", O_RDONLY);
	int     fd4 = open("bonus4.txt", O_RDONLY);
	int     fd5 = open("bonus5.txt", O_RDONLY);
    char    *next_line1;
	char    *next_line2;
	char    *next_line3;
	char    *next_line4;
	char    *next_line5;
    int     count = 0;
	//atexit(ft_leaks);
    if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1 || fd5 == -1)
    {
        printf("Error opening file");
        return 1;
    }
    while (1)
    {
        next_line1 = get_next_line(fd1);
		next_line2 = get_next_line(fd2);
		next_line3 = get_next_line(fd3);
		next_line4 = get_next_line(fd4);
		next_line5 = get_next_line(fd5);
        if (next_line1 == NULL || next_line2 == NULL || next_line3 == NULL 
			|| next_line4 == NULL || next_line5 == NULL)
        {
			printf("El archivo está vacío o es nulo");
            break ;
		}
        else
        {
            printf("Línea %d: %s\n", count, next_line1);
			printf("Línea %d: %s\n", count, next_line1);
			printf("Línea %d: %s\n", count, next_line1);
			printf("Línea %d: %s\n", count, next_line1);
			printf("Línea %d: %s\n", count, next_line1);
            free(next_line1);
			free(next_line2);
			free(next_line3);
			free(next_line4);
			free(next_line5);
            next_line1 = NULL;
			next_line2= NULL;
			next_line3 = NULL;
			next_line4 = NULL;
			next_line5 = NULL;
        }
    }
    close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	//system("leaks -q a.out");
    return 0;
}
