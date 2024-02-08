/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:28:40 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 11:31:36 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char    ft(unsigned int i, char c)
{   
    char            *str;

    str[i] = c + 1;
    return (str[i]);
}

char    ft(unsigned int i, char c)
{
    return (c + (i + 1));
}

int main()
{
    char    *cad = "abcde";
	char    *str2;

	str2 = ft_strmapi(cad, &ft);
	printf("Original %s\n", cad);
    printf("Funcionada %s\n", str2);
    return (0);
}*/

/*static char	*examplef(unsigned int i, char *c)
{
	printf("Esto hace la función con cada char %u: %c\n", i, *c);
}

int main()
{
	char str[] = "Holiiii chuchiii";

	ft_strmapi(str, &examplef);
	return 0;
}*/