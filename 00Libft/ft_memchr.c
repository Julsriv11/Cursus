/*Devuelve un puntero a la posición donde encuentra la primera coincidencia. Esta función busca un char en un array.
La n indica la longitud de mi array, cuanto quiero buscar. La expresión (ptr + i) realiza una suma de punteros. 
ptr es un puntero a un tipo unsigned char, y i es un valor de tipo size_t. Esta suma de punteros se utiliza para 
desplazar el puntero ptr en i unidades de unsigned char, que, en este contexto, es equivalente a 
desplazarse i bytes en la memoria. Luego, la expresión (void *)(ptr + i) realiza un cast del resultado de esa suma 
a un puntero de tipo void *. El casting a void * se utiliza comúnmente para convertir un puntero de 
cualquier tipo a un puntero genérico, ya que void * es un tipo de puntero genérico en C.
En este contexto específico: (ptr + i) da como resultado un puntero desplazado en i bytes desde 
la posición original de ptr en la memoria. (void *)(ptr + i) realiza un cast de ese puntero desplazado a un puntero 
de tipo void *. La razón de usar void * aquí es que memchr y funciones similares generalmente devuelven un puntero genérico, 
ya que la posición de memoria exacta dependerá del tipo de datos con el que se está trabajando. 
El usuario puede luego realizar un casting a un tipo específico si es necesario. 
En tu caso, dado que ft_memchr es una función genérica que trabaja con bytes, usar void * permite al usuario decidir 
el tipo al que desea castear el resultado según sus necesidades.*/

#include <stdio.h>
#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char   *ptr;
    size_t          i;

    ptr = s;
    i = 0;
    while (i < n)
    {
        if (ptr[i] == (unsigned char)c)
            return (void *)(ptr + i);
        i++;
    }
    return NULL;
}

int main()
{
    const char *str = "He is in London";
    const void *found;

    found = ft_memchr(str, 'l', strlen(str));
    printf("Where is Garbi? %p \n", found);
    found = memchr(str, 'L', strlen(str));
    printf("Original one adress: %p \n", found);
    return 0;
}