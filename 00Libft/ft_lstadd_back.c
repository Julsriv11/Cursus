#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *back;
    
    back = ft_lstlast(*lst);
    if(!back)
        *lst = new;
    back->next = new;
}