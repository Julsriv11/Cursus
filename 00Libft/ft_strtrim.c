/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:08:02 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 20:20:45 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}

/*int main()
{
    char    *str = "usualJust feminist peopleusual";
    char    *avoid = "lausu";
    char    *result;
    
    result = ft_strtrim(str, avoid);
    printf("%s \n", result);
    return (0);
}*/

/*int main()
{
	char	*one = "abcdeSOLO QUIERO ESTOabcde";
	char	*fail = "cabed";

	printf("%s", ft_strtrim(one, fail));
	return 0;
}*/