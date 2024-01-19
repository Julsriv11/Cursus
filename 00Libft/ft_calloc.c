/*se utiliza para asignar una cantidad de memoria dinámica en el tiempo de ejecución. 
La función toma dos argumentos, el número de elementos y el tamaño de cada elemento.
A diferencia de malloc, inicializa la memoria a 0, y no con datos no guardados
previamente. Utiliza malloc para alocar memoria, fx permitida. Primero comprueba que
count y size son positivos, si no es así, solo asigna un byte de memoria para evitar 
posibles problemas. Si son positivos, les asigna la memoria necesaria (count * size). 
Verifica si la asignación fue exitosa inicializando todos los bytes de memoria a 0,
 y si no, devuelve NULL. */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;
	size_t	tot_size;

	tot_size = count * size;
	if (!(x = malloc(tot_size)))
		return (0);
	ft_memset(x, 0, tot_size);
	return (x);
}
/*void	*ft_calloc(size_t count, size_t size)
{
	char	*x;
	
	if (count <= 0 || size <= 0)
		x = (char *)malloc(1);
	else
		x = (char *)malloc(count * size);
	if (!x)
		return (NULL);
	return (ft_memset(x, 0, count * size));	
}*/