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
