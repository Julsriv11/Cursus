//comprueba si un int es alfanumérico o no
#include <ctype.h>

int ft_isalpha(int c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return(c);
    else
        return(0);
}