#include "ft_printf.h"

static int  ft_parameters(va_list args, int j, char *phrase)
{
    int x;
    int y;

    x = 0;
    y = 0;
    if (phrase[x] == 'c')
        y = ft_putchar(va_arg(args, int));
    else if (phrase[x] == 'i')
        
    else if (phrase[x] == 's')
        y = ft_putstr(va_arg(args, int));
    else if (phrase[x] == 'p')

    else if (phrase[x] == 'd')

    else if (phrase[x] == 'u')

    else if (phrase[x] == 'x')

    else if (phrase[x] == 'X')

    else if (phrase[x] == '%')

    
}

int ft_printf(char const *phrase, ...)
{
    /*inicia iterando la frase hasta que encuentre el símbolo %.
    Cuando encuentra % para de escribir y mira una posición más, 
    donde nos indica qué tipo de parámetro le estamos pasando.
    Una vez hayamos "escrito" nuestra string utilizando putstr y 
    contando el tamaño que tiene (para añadir más adelante), volvemos
    a la string principal y sigue imprimiendo hasta que vuelva a
    encontrar el %.
    */
int     i; //iterador para leer la frase
int     j; //otro iterador para sumar lo que voy leyendo con %
char    *str; //la frase a escribir
va_list args; //argumentos que le vaya a pasar

i = 0;
j = 0;
str = (char *)phrase;
va_start(args, phrase);
while (str[i])
{
    if (str[i] != '%')
        j = j + ft_putchar(str[i]);
    else if (str[i] == '%')
    {
        j = ft_parameters(args, j, &str[i]);
        i++;
    }
    i++;
}
va_end(args);
return (j);
}