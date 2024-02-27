/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:31:46 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 11:33:09 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*static void	examplef(unsigned int i, char *c)
{
	printf("Esto hace la función con cada char %u: %c\n", i, *c);
}

int main()
{
	char str[] = "Holiiii chuchiii";

	ft_striteri(str, &examplef);
	return 0;
}*/