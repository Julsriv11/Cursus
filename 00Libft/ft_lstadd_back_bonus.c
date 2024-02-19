/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:42:17 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/08 12:26:09 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back; //se utiliza para recorrer la ista hasta el último nodo

	if (!lst)
		return ;
	if (*lst)	//si no es nulo
	{
		back = *lst;	//se inicializa back a la cabeza de la lista lst
		while (back->next)	//se recorre la lista hasta llegar al último nodo
			back = back->next;	
		back->next = new;	//una vez en el último(el siguiente es NULL), se enlaza el nuevo nodo 
	}						//al final de la lista estableciendo el puntero next del último nodo al nuevo nodo
	else
		*lst = new;	//si fuera lst = NULL = está vacío y se asigna new como nueva cabeza de la lista
}
