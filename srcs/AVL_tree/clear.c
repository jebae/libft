#include "libft.h"

static void	recursive_remove_node(
	t_tree_node *root, t_clear_tree_node clear_node)
{
	if (root == NULL)
		return ;
	recursive_remove_node(root->left, clear_node);
	recursive_remove_node(root->right, clear_node);
	clear_node(root);
	ft_memdel((void **)&root);
}

void		clear_avl_tree(t_avl_tree *tree)
{
	recursive_remove_node(tree->root, tree->clear_node);
}