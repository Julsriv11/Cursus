#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *subs;
    size_t  size;
    size_t  j;

    size = ft_strlen(s);
    j = 0;
    if (!s)
        return (NULL);
    if (start >= size)
    {
        subs = (char *)malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = '\0';
		return (subs);
    }
    subs = (char *)malloc(len + 1);
    if (!subs)
        return (NULL);
    while (j < len && s[start] != '\0')
    {
        subs[j] = s[start];
        j++;
        start++;
    }
    subs[j] = '\0';
    return (subs);
}

int main()
{
    char    *str = "Comienza: aquí estamos";
    char    *nueva;
    
    nueva = ft_substr(str, 10, 14);
    printf("%s \n", nueva);
    return (0);
}