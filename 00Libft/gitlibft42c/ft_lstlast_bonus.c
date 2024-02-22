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
