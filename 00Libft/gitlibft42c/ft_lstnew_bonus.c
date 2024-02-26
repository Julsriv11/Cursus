/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:47:23 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/01 10:48:23 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*int main(void)
{
	t_list	*nodo = malloc(sizeof(t_list));

	nodo->content = malloc(sizeof(int));
	*(int *)nodo->content = 11;
	ft_lstnew(nodo);
	printf("Save in my lst %d", *(int *)nodo->content);
	return 0;
}*/
