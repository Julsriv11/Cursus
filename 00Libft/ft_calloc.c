/*se utiliza para asignar una cantidad de memoria dinámica en el tiempo de ejecución. 
La función toma dos argumentos, el número de elementos y el tamaño de cada elemento.
A diferencia de malloc, inicializa la memoria a 0, y no con datos no guardados
perviamente. Se puede utilizar malloc para alocar memoria*/

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*x;
	
	if (count <= 0 || size <= 0)
		x = (char *)malloc(1);
	else
		x = (char *)malloc(count * size);
	if (!x)
		return (NULL);
	return (ft_memset(x, 0, count * size));	
}		
