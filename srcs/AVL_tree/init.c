#include "libft.h"

void	init_avl_tree(
	t_avl_tree *tree, t_key_cmp cmp_key, t_clear_tree_node clear_node)
{
	tree->cmp_key = cmp_key;
	tree->clear_node = clear_node;
	tree->root = NULL;
}