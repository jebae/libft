#include "libft.h"

void		btree_del(t_btree **root, void (*del)(void *content))
{
	if (root == NULL || *root == NULL)
		return ;
	btree_del(&((*root)->left), del);
	btree_del(&((*root)->right), del);
	btree_delone(root, del);
}