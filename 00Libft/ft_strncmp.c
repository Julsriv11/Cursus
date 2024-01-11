#include <stdio.h>
#include <string.h>

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

int main(void)
{
	char s1[] = "PAc34567";
	char s2[] = "00034567";

	printf(" %d\n", ft_strncmp(s1, s2, 3));
	return(0);
}