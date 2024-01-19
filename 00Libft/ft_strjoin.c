#include <stdlib.h>
#include <stdio.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  size1;
    size_t  size2;
    int     i;
    int     j;

    size1 = ft_strlen(s1);
    size2 = ft_strlen(s2);
    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(size1 + size2 + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char	*second = "sesamo";
	char	*first = "Abrete ";

	printf("Contraseña: %s \n", ft_strjoin(first, second));
	return (0);
}