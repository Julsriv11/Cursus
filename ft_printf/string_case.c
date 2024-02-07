#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (!str[i] == NULL) // write(1, "NULL", 4) i = 4, return i
        return (0);
    else
    {
        while (str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    return (i);
}