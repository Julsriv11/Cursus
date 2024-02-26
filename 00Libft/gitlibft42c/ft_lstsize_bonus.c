/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:49:05 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 10:51:19 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*count;
	int		i;

	count = lst;
	i = 0;
	while (count != NULL)
	{
		count = count->next;
		i++;
	}
	return (i);
}

/*int main(void)
{
	t_list x;
	t_list y;
	t_list z;

	x.content = malloc(sizeof(int));
	*(int *)x.content = 1;
	x.next = &y;
	y.content = malloc(sizeof(int));
	*(int *)y.content = 2;
	y.next = &z;
	z.content = malloc(sizeof(int));
	*(int *)z.content = 3;
	z.next = NULL;
	printf("Size of lst is %d\n", ft_lstsize(&x));
	free(x.content);
	free(y.content);
	free(z.content);
	return 0;
}*/