/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:17:09 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/27 16:23:07 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*ft_mem_n(int len)
{
	char	*mem;

	mem = malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	mem[len] = '\0';
	return (mem);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_n_len(nbr);
	str = ft_mem_n(len);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	if (nbr == 0)
		str[i] = '0';
	while (nbr != 0)
	{
		str[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int print_num(int x)
{
    int		len;
	long	nb;
    
	nb = x;
	if (x < 0)
	{
		len += print_c('-');
		x = x * -1;
	}
	if (x < 10)
	{
		len += print_c(x + '0');
	}
	else
	{
		len += print_num(x / 10);
		len += print_num(x % 10);
	}
    return (len);
}
