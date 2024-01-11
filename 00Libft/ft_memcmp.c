/*Compara bytes de memoria entre string en vez de el contenido de estas string, es decir, compara bloques de memoria sin
interpretar su contenido como cadenas de char. Devuelve un entero que indica la relación entre los bloques de memoria comparados. 
Puede ser negativo si el primer bloque es menor, positivo si el primer bloque es mayor o cero si son iguales. El parámetro
n, en este caso es el tamaño de bytes a comparar en vez de nº máx char como en strncmp*/

#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char   *ptr_s1;
    const unsigned char   *ptr_s2;
    size_t  i;

    ptr_s1 = s1;
    ptr_s2 = s2;
    i = 0;
    while (*ptr_s1 == *ptr_s2 && *ptr_s1 != '\0' && *ptr_s2 != '\0')
    {
        
    }
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (i >= n)
		return (0);
	else
		return (s1[i] - s2[i]);
}