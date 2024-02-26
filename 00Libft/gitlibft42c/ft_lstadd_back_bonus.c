/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:42:17 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/13 15:58:44 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!lst)
		return ;
	if (*lst)
	{
		back = *lst;
		while (back->next)
			back = back->next;
		back->next = new;
	}
	else
		*lst = new;
}

/*int main()
{
     t_list *root = malloc(sizeof(t_list));
	 t_list	*new_nodo = malloc(sizeof(t_list));

     root->content = malloc(sizeof(int));
	 *(int *)root->content = 21;
	 new_nodo->content = malloc(sizeof(int));
	 *(int *)new_nodo->content = 11;
     ft_lstadd_back(&root, new_nodo);
     t_list *curr = root;
     while (curr != NULL)
     {    
          printf("%d\n", *(int *)curr->content);
          curr = curr->next; //Esto sirve para avanzar
     }
     return (0);
}*/