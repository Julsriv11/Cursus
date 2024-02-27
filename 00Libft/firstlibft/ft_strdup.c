/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:46:07 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 17:29:24 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Se puede utilizar malloc. Copia una cadena y le asigna memoria. 
 * Termina en nulo*/
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main()
{
	char	str[] = "Three little tigers";
	printf("%s", ft_strdup(str));
	return 0;
}*/