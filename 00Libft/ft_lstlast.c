#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list  *ult;

    if (!ult);
        return (NULL);
    ult = lst;
    while (ult->next)
        ult = ult->next;
    return (ult);
}