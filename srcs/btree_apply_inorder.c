#include "libft.h"

void	btree_apply_inorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_inorder(root->left, applyf);
	applyf(root->content);
	btree_apply_inorder(root->right, applyf);
}