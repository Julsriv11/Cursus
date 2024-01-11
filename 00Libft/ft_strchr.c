
/*Esta fx devuelve un puntero a la posición donde coincide el char y muestra la subcadena desde la coincidencia
por tanto, si modificamos la subcadena también modificamos la cadena principal ya que comparten dirección de memoria donde
se guardan. Si no se encuentra el char en la str, se devolverá NULL.
Cuando tenemos un const char *s, significa que tenemos un puntero mutable <=> nos permite cambiar donde apunta el parámetro
pero no el CONTENIDO de la cadena. Si se encuentra el carácter, devuelve un puntero a la posición actual de la cadena (s). 
La conversión a (char *) se realiza para que coincida con el tipo de retorno de la función.*/

#include <stdio.h>
#include <string.h>

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return (NULL);
}

int main()
{
    char    *str = "John Mr Snow";
    printf ("Who is cool? %s \n", ft_strchr (str, 'Z'));
    return 0;
}