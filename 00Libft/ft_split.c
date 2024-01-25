/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:32 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/22 18:08:47 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*En count_w contamos cuantas subcadenas tendríamos en nuestra string de 
 * acuerdo al tamaño de s. Hacemos dos bucles, un primero para comprobar que
 * va de un separador a otro y sumar i. y otro bucle para comprobar desde un 
 * separador a otro, y que procese la subcadena.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

static int ft_count_w(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && i == 0)
	   	{
			i = 1;
			count++;
		}
      	else if (*s == c)
			i = 0;
		s++;
   }
	return (count);
}

static char	*ft_memsubs(const char *s, int ini, int fin)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((fin - ini + 1) * sizeof(char));
	if (!ptr)
      return (NULL);
	while (ini < fin)
	{
		ptr[i] = s[ini];
		i++;
		ini++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	*ft_freedom(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void ft_start_iti(size_t *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = -1;
}

char    **ft_split(char const *s, char c)
{
	char	**result;
	size_t	len;
	size_t	i;
	int		j;
	int		k;

	len = ft_strlen(s);
	ft_start_iti(&i, &j, &k);
	result = (char **)malloc(sizeof(char*) * (ft_count_w(s, c) + 1));
	if (!result)
		return (NULL);
	while (i <= len)
	{
		if (s[i] != c && k < 0)
			k = i;
		else if (s[i] == c || i == len)
		{
			result[j] = ft_memsubs(s, k, i);
			if (!(result[j]))
				return (ft_freedom(result, j));
         k = -1;
		 j++;
     	}
		i++;
	}
	return (result);
}

int main()
{
    char    *str = "Viento en popa,a toda vela,no corta el mar,sino vuela";
    char    del = ',';
	char    sep = ',';
   	char     **own;
	int		i = 0;
	char	*man;

   	own = ft_split(str, del);
	printf("Propia:\n");
	while (own[i] != NULL)
	{
		printf("%s \n", own[i]);
		i++;
	}
	man = strtok(str, sep);
	printf("Man:\n");
	while (man != NULL)
	{
		printf("%s \n", man);
		i++;
	}
	return (0);
}
