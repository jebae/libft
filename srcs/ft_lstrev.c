#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*pre;
	t_list	*cur;
	t_list	*temp;

	pre = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	*alst = pre;
}
