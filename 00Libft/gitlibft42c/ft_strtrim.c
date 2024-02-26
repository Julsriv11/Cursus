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

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	result = ft_substr(s1, i, j - i);
	return (result);
}

/*int main()
{
	char	*one = "abcdeSOLO QUIERO ESTOabcde";
	char	*fail = "cabed";

	printf("%s", ft_strtrim(one, fail));
	return 0;
}*/