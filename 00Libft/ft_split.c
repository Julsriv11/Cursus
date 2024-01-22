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
	unsigned int	i;
	int            count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
	   	i++;
      	else
		{ 
			count++;
			while (s[i] && (s[i] != c))
         		i++;
		}
   }
	return (count);
}

static char	*ft_memsubs(const char *s, size_t n)
{
	char	*ptr;
	size_t	i;
	size_t   len;

	i = 0;
	len = ft_strlen(s);
	if (n > len)
      n = len;
	ptr = (char *) malloc(sizeof(char) * n + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0' && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	ft_freedom(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char    **ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**result;
	size_t	len;

	i = 0;
	k = 0;
	len = ft_strlen(s);
	result = (char **)malloc(sizeof(char*) * (ft_count_w(s, c) + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		while (s[i] == c)
         i++;
		j = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > j)
		{
         result[k] = ft_memsubs(s + j, i - j);
         k++;
      }
	}
	result[k] = NULL;
	ft_freedom(result);
	return (result);
}

int main()
{
    char    *str = "Viento en popa, a toda vela, no corta el mar, sino vuela";
    char    del = ',';
   	char     **own;
	//char     *token;
	int		i = 0;

   	own = ft_split(str, del);
	printf("Propia:\n");
	while (own[i] != NULL)
	{
		printf("%s \n", own[i]);
		i++;
	}
	/*token = strtok((char *)str, &del);
	printf("Manual:\n");
	while (token[i] != NULL)
	{
		printf("%s\n", token[i]);
		i++;
	}*/
	return (0);
}
