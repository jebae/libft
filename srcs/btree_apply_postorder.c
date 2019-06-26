#include "libft.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_postorder(root->left, applyf);
	btree_apply_postorder(root->right, applyf);
	applyf(root->content);
}