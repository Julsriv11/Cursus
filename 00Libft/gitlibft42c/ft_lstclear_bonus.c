/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:27:14 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/22 11:30:18 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		aux = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = aux;
	}
	free(*lst);
	*lst = NULL;
}
