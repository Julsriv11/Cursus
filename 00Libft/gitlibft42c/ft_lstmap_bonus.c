/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:32:03 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/22 11:33:52 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*con el while iteramos la lista lst, en cada iteración se llama con f al 
contenido de la lst (lst->content) y se aplica f a c/elemento. El resultado
de cada iteración se almacena en una nueva estructura newelem. Si existe 
error al crear newelem, se libera la memoria asignada con lstclear. Si por
el contrario se crea bien, se añade cada newelem a la nueva lista newlst.
Se actualiza con lst = lst->next, para realizar de nuevo la iteración.
Se retorna la nueva lista creada*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newelem = ft_lstnew(f(lst->content));
		if (newelem == NULL)
			return (ft_lstclear(&newelem, del), NULL);
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}

/*int *resultadd(void *content)
{
    int *num = (int *)content;
    int *square = malloc(sizeof(int));
    if (square == NULL)
        return (NULL);
    *square = *num * *num;
    return (square);
}

void del_int(void *content)
{
    free(content);
}

int main(void)
{
    t_list *x = malloc(sizeof(t_list));
    t_list *y = malloc(sizeof(t_list));
    t_list *z = malloc(sizeof(t_list));

    int *int_x = malloc(sizeof(int));
    int *int_y = malloc(sizeof(int));
    int *int_z = malloc(sizeof(int));

    *int_x = 2;
    *int_y = 3;
    *int_z = 4;

    x->content = int_x;
    x->next = y;
    y->content = int_y;
    y->next = z;
    z->content = int_z;
    z->next = NULL;

    t_list *squared_list = ft_lstmap(x, resultadd, del_int);

    t_list *curr = squared_list;
    while (curr != NULL)
    {
        printf("%d\n", *(int *)curr->content);
        curr = curr->next;
    }

    // Liberar memoria
    while (squared_list != NULL)
    {
        t_list *temp = squared_list;
        squared_list = squared_list->next;
        free(temp->content);
        free(temp);
    }

    return 0;
}*/
