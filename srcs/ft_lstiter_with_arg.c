#include "libft.h"

void	ft_lstiter_with_arg(t_list *lst,\
	void (*f)(t_list *elem, void *arg), void *arg)
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		(*f)(lst, arg);
		lst = lst->next;
	}
}
