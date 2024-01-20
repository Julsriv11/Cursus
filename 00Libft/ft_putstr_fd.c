#include <string.h>
#include <unistd.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void    ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}