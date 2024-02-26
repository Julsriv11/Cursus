/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:45:59 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 16:14:37 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ult;

	ult = lst;
	if (ult == NULL)
		return (NULL);
	while (ult->next != '\0')
		ult = ult->next;
	return (ult);
}

#include <stdio.h>
int main(void)
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
	printf("Size of lst is %d\n", ft_lstlast(&x)->content);
	free(x.content);
	free(y.content);
	free(z.content);
	return 0;
}