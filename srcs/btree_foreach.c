#include "libft.h"

void		btree_foreach(
	t_btree *root,
	void (*f)(void *content)
)
{
	if (root == NULL)
		return ;
	btree_foreach(root->left, f);
	f(root->content);
	btree_foreach(root->right, f);
}