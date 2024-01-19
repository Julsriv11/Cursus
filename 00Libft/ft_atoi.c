/*Preguntar si hay que manejar máximo y que tipo de int*/
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long long unsigned	x;
	long long unsigned	max;	
	int			sign;

	x = 0;
	sign = 1;
	max = 9223372036854775807;
	while (*str != '\0')
	{
		while (*str == ' ' || *str  == ' ' || *str == '\f' || *str == '\n' || 
			*str == '\r' || *str == '\t' || *str == '\v')
			str++;
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= 48 && *str <= 57)
		{
			x = 10 * x + (*str - '0');
			if (x > max && sign == 1)
				return (-1);
			if (x > max + 1 && sign == -1)
				return (0);
			str++;
		}
		break;
	}
	return (sign * x);
}
