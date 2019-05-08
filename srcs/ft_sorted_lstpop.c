#include "libft.h"

t_list		*ft_sorted_lstpop(t_list **alst)
{
	t_list	*to_pop;

	if (alst == NULL)
		return (NULL);
	to_pop = *alst;
	*alst = to_pop->next;
	return (to_pop);
}
