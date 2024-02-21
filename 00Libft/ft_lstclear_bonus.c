#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *aux;

    if (lst == NULL || del == NULL)
        return ;
    while (*lst != NULL)
    {
        aux = (*lst)->next; //utilizo aux para avanzar en lst y buscar cada nodo siguiente
        (*del)((*lst)->content); //en cada nodo, realizo la función del en el contenido y después
        free(lst);               //lo libero
        *lst = aux;              //lo vuelvo a igualar a aux para que empieze, hasta que se encuentre null
    }
    while (*lst !=  NULL)
    {
        aux = (*lst)->next;
        ft_lstdelone(*lst, del);
    }
    free(*lst);
    *lst = NULL;
}