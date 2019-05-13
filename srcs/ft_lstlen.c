#include "libft.h"

size_t		ft_lstlen(t_list *lst)
{
	size_t		len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
