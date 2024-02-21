#include "ft_printf.h"

static int ptr_len(unsigned long long ptr)
{
    int len;

    len = 0;
    while (ptr != 0)
    {
        len++;
        ptr = ptr / 16;
    }
    return (len);
}

static void put_ptr(unsigned long long ptr)
{
    if (ptr >= 16)
    {
        put_ptr(ptr / 16);
        put_ptr(ptr % 16);
    }
    else
    {
        if (ptr <= 9)
            print_c(ptr + '0');
        else
            print_c(ptr - 10 + 'a');
    }
}

int print_ptr(unsigned long long ptr)
{
    int printlen;

    printlen = 0;
    printlen += write(1, "0x", 2);
    if (ptr == NULL)
       printlen += write(1, "0", 1);
    else
    {
        put_ptr(ptr);
        printlen += ptr_len(ptr);
    }
    return (ptr_len);
}