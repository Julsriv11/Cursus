/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliaariasiniesta <juliaariasiniesta@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:55 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/01 21:14:29 by juliaariasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)	
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		str[i++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

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
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	if (count > 0 && size > 0 && SIZE_MAX / size < count)
		return (NULL);
	x = (void *)malloc(count * size);
	if (!x)
		return (0);
	ft_memset(x, 0, count * size);
	return (x);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}