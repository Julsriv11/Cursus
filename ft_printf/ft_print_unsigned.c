#include "ft_printf.h"

static int num_len(unsigned int num)
{
    int i;

    i = 0;
    while (num != 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}

static char *uitoa(unsigned int num)
{
    char *x;
    int size;

    size = num_len(num);
    x = (char *)malloc(sizeof(char) * size + 1);
    if (x == NULL)
        return (NULL);
    x[size] = '\0';
    while (x != '\0')
    {
       x[size - 1] = ((num % 10) + 48);
       num = num / 10;
       size--;
    }
    return (x);
}

int print_unsigned(unsigned int n)
{
    int len;
    char *num;

    len = 0;
    if (n == 0)
        len += write(1, "0", 1);
    else
    {
        num = uitoa(n);
        len += print_str(num);
        free(num);
    }
    return (len);
}