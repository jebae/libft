#include "libft.h"

static void	*search_recursive(
	void *key, t_tree_node *node, t_key_cmp cmp)
{
	int		cmp_res;

	if (node == NULL)
		return (NULL);
	cmp_res = cmp(key, node->key);
	if (cmp_res == 0)
		return (node->val);
	else if (cmp_res > 0)
		return (search_recursive(key, node->right, cmp));
	return (search_recursive(key, node->left, cmp));
}

void	*get_avl_tree_val(void *key, t_avl_tree *tree)
{
	return (search_recursive(key, tree->root, tree->cmp_key));
}