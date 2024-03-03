#include "get_next_line.h"

// char    *join_and_free(char *static_lines, char *buffer)
// {
//     char    *ptr;

//     ptr = ft_strjoin(static_lines, buffer);
//     return (ptr);
// }

char    *go_next_line(char *static_lines)
{   
    int i;
    int j;
    char *next_line;

    i = 0;
    while (static_lines[i] && static_lines[i] != '\n')
        i++;
    if (!static_lines[i])
    {
        free(static_lines);
        return (NULL);
    }
    next_line = ft_calloc((ft_strlen(static_lines) - i + 1), sizeof(char));
    i++;
    j = 0;
    while (static_lines[i] != '\0')
        next_line[j++] = static_lines[i++];
    free(static_lines);
    return (next_line);
}
char    *returned_line(char *static_lines)   //vamos a ir a la siguiente línea y actualizar el ptr de la estática
{
    char    *end_of_line;
    int     i;

    i = 0;
    if (!static_lines[i])
        return (NULL);
    while (static_lines[i] && static_lines[i] != '\n')
        i++;
    end_of_line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (static_lines[i] && static_lines[i] != '\n')
    {
        end_of_line[i] = static_lines[i];
        i++;
    }
    if (static_lines[i] && static_lines[i] == '\n')
        end_of_line[i] = '\n';
    return (end_of_line);
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
        buffer[bytes_read] = 0;  //se pone null al final según haya leído con n bytes_read
        //static_lines = join_and_free(static_lines, buffer); //se llama a función que une lo leído, a la variable estática
        static_lines = ft_strjoin(static_lines, buffer);
        if (ft_strchr(static_lines, '\n')) // si encuentra un salto de línea, ha leído una línea y rompe while
            break ;
    }
    //free(buffer);
    return (static_lines);
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
    static_lines = go_next_line(static_lines);
    return (result);
}

int main(void)
{
    int     fd = open("nothing.txt", O_RDONLY);
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
            break ;
        count++;
        printf("Línea %d: %s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
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