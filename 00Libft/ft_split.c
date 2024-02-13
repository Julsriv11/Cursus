/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:32 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 17:34:49 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*En count_w contamos cuantas subcadenas tendríamos en nuestra string de 
 * acuerdo al tamaño de s. Hacemos dos bucles, un primero para comprobar que
 * va de un separador a otro y sumar i. y otro bucle para comprobar desde un 
 * separador a otro, y que procese la subcadena.*/

#include <stdio.h>
#include "libft.h"

static int	ft_count_w(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static size_t	len(const char *s, char c)
{
	size_t	x;

	x = 0;
	while (s && s[x] != '\0' && s[x] != c)
		x++;
	return (x);
}

static void	*ft_freedom(char **str, int count)
{
	int	i;

	i = 0;
	while (str && i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s)
		return (NULL);
	k = ft_count_w(s, c);
	result = ft_calloc(k + 1, sizeof(char *));
	if (!result)
		return (NULL);
	j = -1;
	while (++j < k)
	{
		i = -1;
		while (*s == c)
			s++;
		result[j] = ft_calloc(len(s, c) + 1, sizeof(char));
		if (!result[j])
			return (ft_freedom(result, j));
		while (s[++i] != c && s[i] != '\0')
			result[j][i] = s[i];
		s += i;
	}
	return (result);
}

/*int main()
{
    char    *str = "Viento en popa, a toda vela, no corta el mar, sino vuela ";
    char    del = ' ';
    char     **own;
	int		i = 0;

   	own = ft_split(str, del);
	printf("Propia:\n");
	while (own[i] != NULL)
	{
		printf("%s \n", own[i]);
		i++;
	}
	return (0);
}*/

/*int main ()
{
	char	*one = "Todo,separado,por,palabra";
	char	**home;
	char	sep = ',';
	int		i = 0;

	home = ft_split(one, sep);
	while (home[i] != '\0')
	{
		printf("%s\n", home[i]);
		i++;
	}
	return 0;
}*/