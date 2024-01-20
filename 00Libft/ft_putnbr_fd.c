#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    char	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			num = '-';
            n = -n;
			write(fd, &num, 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
        }
		num = '0' + n % 10;
		write(fd, &num, 1);
	}
}