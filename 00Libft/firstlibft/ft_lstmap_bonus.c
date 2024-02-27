#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *newelem;

    if (lst == NULL || f == NULL || del == NULL)
        return (NULL);
    newlst =  NULL;
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

/*con el while iteramos la lista lst, en cada iteración se llama con f al 
contenido de la lst (lst->content) y se aplica f a c/elemento. El resultado
de cada iteración se almacena en una nueva estructura newelem. Si existe 
error al crear newelem, se libera la memoria asignada con lstclear. Si por
el contrario se crea bien, se añade cada newelem a la nueva lista newlst.
Se actualiza con lst = lst->next, para realizar de nuevo la iteración.
Se retorna la nueva lista creada*/