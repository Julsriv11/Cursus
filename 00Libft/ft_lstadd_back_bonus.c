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

/*void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	back = ft_lstlast(*lst);
	if (!back)
		*lst = new;
	else
		back->next = new;
	new->next = NULL;
}*/

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
