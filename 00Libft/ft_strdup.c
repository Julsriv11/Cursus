/*Se puede utilizar malloc. Copia una cadena y le asigna memoria. Termina en nulo*/

#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	ptr = (char *) malloc(sizeof(char) * (size + 1));
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[size] = '\0';
	return (ptr);
}
