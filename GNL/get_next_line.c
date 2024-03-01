/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliaariasiniesta <juliaariasiniesta@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:34 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/02 00:02:00 by juliaariasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_stash(char *reach_lines)
{
    
}

char    *get_each_lines(char *reach_lines)
{
    char *each_line;
    int   i;

    i = 0;
    while (reach_lines[i] && reach_lines != '\n')
        i++;
    each_line = malloc(sizeof(char) * (i + 2));
    if (each_line == NULL)
        return (NULL);
    i = 0;
    while (reach_lines[i] && reach_lines != '\n') //copia la línea extraída de la estática a la que devolverá con each_line
    {
        each_line[i] = reach_lines[i];
        i++;
    }
    each_line[i] = '\0';
    return (each_line);
}
char    *get_buf(char *reach_lines, int fd)  //esta f(x) nos lee el archivo y almacena cada char leído en bytes_read
{
    int     bytes_read;
    char    *buffer;

    bytes_read = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    while (!ft_strchr(reach_lines, '\n') && bytes_read != 0)    //comprueba que no se encuentra con '\n'
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return (free(buffer), NULL);
        // {
        //     free(reach_lines);
        //     free(buffer);
        //     return (NULL);
        // }
        buffer[bytes_read] = '\0';  //con el tamaño del archivo leído, antes de unirlo, se pone el nulo al final.
        reach_lines = ft_strjoin(reach_lines, buffer);
   }
   free(buffer);
   return (reach_lines);
}

char    *get_next_line(int fd)
{
    char static *reach_lines;
    char        *result_lines;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    reach_lines = get_buf(reach_lines, fd);
    if (reach_lines == NULL)
        return (NULL);
    result_lines = get_each_lines(reach_lines);
    reach_lines = get_stash(reach_lines);
     return (result_lines);
}
//otra forma

char    *join_and_free(char static_lines, char buffer)
{
    char    *ptr;

    ptr = ft_strjoin(static_lines, buffer);
    free(buffer);
    return (ptr);
}
char    *returned_line(char static_lines)
{
    
}

char    *read_file(char *static_lines, int fd)  //esta función lee el archivo, y obtiene el "tamaño"
{
    char    *buffer;
    int     bytes_read;

    if (static_lines == NULL)
        static_lines = ft_calloc(1, 1);
    buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0)  //comienzo a leer el archivo, para ello primero
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE); //leo el archivo y leo una cantidad de n bytes
        if (bytes_read <= 0)    //si está vacio, liberas y retornas null
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';  //se pone null al final según haya leído con n bytes_read
        static_lines = join_and_free(static_lines, buffer); //se llama a función que une lo leído, a la variable estática
        if (ft_strchr(buffer, '\n')) // si encuentra un salto de línea, ha leído una línea y rompe while
            break ;
    }
    free(buffer);
    return (bytes_read);
}

char    *get_next_line(int fd)
{
    static char *static_lines;
    char        *result;

    if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE == INT_MAX)
        return (NULL);
    static_lines = read_file(static_lines, fd);
    if (static_lines == NULL)
        return (NULL);
    result = returned_line(static_lines);
    static_lines = next_line(static_lines);
    return (result);
}

// int main(void)
// {
//     int     fd = open("testeo.txt", O_RDONLY);
//     char    *next_line;
//     int     count = 0;
//     if (fd == -1)
//     {
//         printf("Error opening file");
//         return 1;
//     }
//     while (1) // para llamar infinitamente a la función.
//     {
//         next_line = get_next_line(fd);
//         if (next_line == NULL)
//             break;
//         count++;
//         printf("Línea %d: %s\n", count, next_line);
//         free(next_line);
//         next_line = NULL;
//     }
//     close(fd);
//     return 0;
// }

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