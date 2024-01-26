/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:41:42 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/11 18:42:44 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	else
		return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/*int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}*/

/*int main(void)
{
	char s1[] = "test\200";
	char s2[] = "test\0";

	printf(" %d\n", ft_strncmp(s1, s2, 6));
	printf(" %d\n", strncmp(s1, s2, 6));
	return(0);
}*/
