//comprueba si un int es un dígito
#include <ctype.h>

int ft_isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return(c);
    else
        return(0);
}