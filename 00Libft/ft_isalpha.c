//comprueba si un int es alfabético o no
#include <ctype.h>

int ft_isalpha(int c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return(c);
    else
        return(0);
}