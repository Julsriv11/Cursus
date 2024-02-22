/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:47:37 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 16:01:56 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (start >= size)
	{
		subs = (char *)malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = 0;
		return (subs);
	}
	if (len > size - start)
		len = size - start;
	subs = ft_calloc(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}
