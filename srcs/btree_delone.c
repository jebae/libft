#include "libft.h"

void		btree_delone(t_btree **node, void (*del)(void *content))
{
	if (node == NULL || *node == NULL)
		return ;
	if ((*node)->content != NULL && del != NULL)
		del((*node)->content);
	ft_memdel((void **)node);
}