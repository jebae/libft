#include "libft.h"

void	ft_sorted_lstadd(t_list **alst, t_list *n, int (*compare)(t_list *, t_list *))
{
	t_list	*pre;
	t_list	*cur;

	if (alst == NULL || n == NULL)
		return ;
	pre = NULL;
	cur = *alst;
	while (cur != NULL && compare(n, cur) > 0)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre != NULL)
		pre->next = n;
	else
		*alst = n;
	n->next = cur;
}
