/* La función strrchr() es idéntica a strchr(), salvo que localiza la última aparición de c. 
Se utiliza un puntero auxiliar para mantener la posición del último lugar donde se encontró el char buscado. 
Esto se actualiza en cada iteración del bucle siempre que se encuentre el carácter.*/

#include <stdio.h>
#include <string.h>

char    *ft_strrchr(const char *s, int c)
{
    const char  *last;

    last = NULL;
    while (*s != '\0')
    {
        if (*s == c)
           last = s;
        s++;
    }
    if (*s == c)
        return (char *)s;
    return (char *)last;
}

int main()
{
    char    *str = "John Mr MmSnow";
    printf ("Who is cool? %s \n", ft_strrchr (str, 'Z'));
    printf("The original %s \n", strrchr(str, 'z'));
    return 0;
}