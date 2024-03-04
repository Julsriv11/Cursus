/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:55:26 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/04 20:16:22 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*go_next_line(char *static_lines) //tras ser retornada, la libera y retorna el resto
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
	next_line = (char *)malloc((ft_strlen(static_lines) - (i + 1)) * sizeof(char));
	if (next_line == NULL)
		return (NULL);
	i++;
	j = 0;
	while (static_lines[i] != '\0')
		next_line[j++] = static_lines[i++];
	next_line[j] = '\0';
	free(static_lines);
	return (next_line);
}

char	*returned_line(char *static_lines)	//tras leer la primera línea, la devuelve
{
	char	*line_completed;
	int		i;

	i = 0;
	if (!static_lines[i])
		return (NULL);
	while (static_lines[i] != '\0' && static_lines[i] != '\n')
		i++;
	line_completed = malloc((i + 2) * sizeof(char)); //el +2 es para el nulo y el salto de línea en cuanto a memoria?
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

char	*read_file(char *static_lines, int fd)  //esta función lee la primera línea de mi archivo, por tanto debe manejar si le pasa un nulo, uno vacío...
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(static_lines, '\n'))  //comienzo a leer mientras no encuentre salto línea
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); //lee y cuenta n bytes
		if (bytes_read <= 0)    //si está vacio, liberas y retornas null
		{
			free(static_lines);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';  //se pone null al final según haya leído la primera línea con n bytes_read
		static_lines = ft_strjoin(static_lines, buffer); //se unirá cada línea
	}
    free(buffer);
    return (static_lines);
}

char	*get_next_line(int fd)
{
	static char	*static_lines;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	static_lines = read_file(static_lines, fd);
	if (static_lines == NULL)
		return (NULL);
	result = returned_line(static_lines);
	static_lines = go_next_line(static_lines);
	return (result);
}
// void ft_leaks()
// {
// 	system("leaks -q a.out");
// }

int main(void)
{
    int     fd = open("testeo.txt", O_RDONLY);
    char    *next_line;
    int     count = 0;
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
    }
    while (1) // para llamar infinitamente a la función.
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
        {
			printf("El archivo está vacío o es nulo");
            break ;
		}
        count++;
        printf("Línea %d: %s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
	   //system("leaks -q a.out");
    return 0;
}

/*fd 0 = entrada estándar 1 = salida estándar 2 = error
La función read recuerda donde se quedó leyendo la última vez que fue llamada, de forma que
si le das el tamaño de lectura de tu archivo o de lo que contenga, te leera todo y te 
el final del archivo
ssize_t     read(int fildes, void *buf, size_t nbyte); retorna el número de bytes que lee.
Se necesita guardar lo que se va leyendo en una variable <=> se acumula la información en una
variable para que luego retorno todo lo almacenado. En inglés, reserva se llama stash.
Una variable estática es aquella que mantiene su valor entre 2 llamadas a una función por
lo que es el contador que acumula la info que se va leyendo en el fd. Se les asigna memoria en el segmento
de los datos y no en el segmento de pila. Se deben iniciar a 0 sino se inician explícitamente*/

// char    *join_and_free(char *static_lines, char *buffer)
// {
//     char    *ptr;

//     ptr = ft_strjoin(static_lines, buffer);
//     return (ptr);
// }