/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:55:26 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/05 19:43:13 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*go_next_line(char *static_lines)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
		i++;
	if (static_lines[i] == '\0')
	{
		free(static_lines);
		return (NULL);
	}
	next_line = (char *)malloc((ft_strlen(static_lines) - 
								(i + 1) + 1) * sizeof(char));
	if (next_line == NULL)
	{
		free(static_lines);
		return (NULL);
	}
	i++;
	j = 0;
	while (static_lines[i] != '\0')
		next_line[j++] = static_lines[i++];
	next_line[j] = '\0';
	free(static_lines);
	return (next_line);
}

char	*returned_line(char *static_lines)
{
	char	*line_completed;
	int		i;

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
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
	{
		line_completed[i] = static_lines[i];
		i++;
	}
	if (static_lines[i] == '\n')
	{
		line_completed[i] = static_lines[i];
		i++;
	}
	line_completed[i] = '\0';
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
	static char	*static_lines;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_lines = read_file(static_lines, fd);
	if (static_lines == NULL || static_lines == 0)
		return (NULL);
	result = returned_line(static_lines);
	static_lines = go_next_line(static_lines);
	return (result);
}
// void ft_leaks()
// {
// 	system("leaks -q a.out");
// }

// int main(void)
// {
//     int     fd = open("testeo.txt", O_RDONLY);
//     char    *next_line;
//     int     count = 0;
// 	// atexit(ft_leaks);
//     if (fd == -1)
//     {
//         printf("Error opening file");
//         return 1;
//     }
//     while (1) // para llamar infinitamente a la función.
//     {
//         next_line = get_next_line(fd);
//         if (next_line == NULL)
//         {
// 			printf("El archivo está vacío o es nulo");
//             break ;
// 		}
//         count++;
//         printf("Línea %d: %s\n", count, next_line);
//         free(next_line);
//         next_line = NULL;
//     }
//     close(fd);
// 	   //system("leaks -q a.out");
//     return 0;
// }

