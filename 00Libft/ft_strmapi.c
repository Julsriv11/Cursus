#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t  len;
    size_t  i;
    char    *str;

    i = 0;
    len = ft_strlen(s);
    if (!s || !f)
        return (NULL);
    if (!(str = malloc((len + 1) * sizeof(char))))
        return (0);
    while (i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

/*char    ft(unsigned int i, char c)
{   
    char            *str;

    str[i] = c + 1;
    return (str[i]);
}

char    ft(unsigned int i, char c)
{
    return (c + (i + 1));
}

int main()
{
    char    *cad = "abcde";
	char    *str2;

	str2 = ft_strmapi(cad, &ft);
	printf("Original %s\n", cad);
    printf("Funcionada %s\n", str2);
    return (0);
}*/