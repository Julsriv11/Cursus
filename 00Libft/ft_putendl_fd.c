#include <unistd.h>
#include <string.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void    ft_putendl_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
}