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

#include <stdio.h>
#include "libft.h"

/*char    ft(unsigned int i, char c)
{
	(void)i;
	if (ft_isdigit(c))
		return ('x');
	return(c);
}*/

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

/*int main()
{
    char    *cad = "abcde123abc";
	char    *str2;

	str2 = ft_strmapi(cad, &ft);
	printf("Original %s\n", cad);
    printf("Funcionada %s\n", str2);
    return (0);
}*/