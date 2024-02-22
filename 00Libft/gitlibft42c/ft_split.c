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

static void	ft_freedom(char **str, int count)
{
	while (count >= 0)
		free (str[count--]);
	free (str);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		j;
	size_t		k;

	if (s == NULL)
		return (NULL);
	k = ft_count_w(s, c);
	result = ft_calloc(k + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	j = -1;
	while (++j < k)
	{
		i = -1;
		while (*s == c)
			s++;
		result[j] = ft_calloc(len(s, c) + 1, sizeof(char));
		if (!result[j])
			return (ft_freedom(result, j), NULL);
		while (s[++i] != c && s[i] != '\0')
			result[j][i] = s[i];
		s += i;
	}
	return (result);
}
