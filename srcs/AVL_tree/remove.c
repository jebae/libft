#include "libft.h"

static t_tree_node	*switch_with_left_most(t_tree_node *node)
{
	t_tree_node		*parent;
	t_tree_node		*left_most;
	t_tree_node		tmp;

	parent = NULL;
	left_most = node->right;
	while (left_most->left)
	{
		parent = left_most;
		left_most = left_most->left;
	}
	tmp = *left_most;
	left_most->left = node->left;
	left_most->right = node->right;
	node->left = NULL;
	node->right = tmp.right;
	node->height = tmp.height;
	if (parent == NULL)
		left_most->right = node;
	else
		parent->left = node;
	return (left_most);
}

static t_tree_node	*dfs_remove_node(
	void *key, t_tree_node *node,
	t_key_cmp cmp, t_clear_tree_node clear_node);

static t_tree_node	*remove_node(
	t_tree_node *node, t_key_cmp cmp, t_clear_tree_node clear_node)
{
	t_tree_node	*sub;

	if (node->left && node->right)
	{
		sub = switch_with_left_most(node);
		sub->right = dfs_remove_node(
			node->key, sub->right, cmp, clear_node);
		return (sub);
	}
	sub = (node->left == NULL) ? node->right : node->left;
	clear_node(node);
	ft_memdel((void **)&node);
	return (sub);
}

static t_tree_node	*dfs_remove_node(
	void *key, t_tree_node *node,
	t_key_cmp cmp, t_clear_tree_node clear_node)
{
	int	cmp_res;

	if (node == NULL)
		return (NULL);
	cmp_res = cmp(key, node->key);
	if (cmp_res == 0)
		node = remove_node(node, cmp, clear_node);
	else if (cmp_res > 0)
		node->right = dfs_remove_node(key, node->right, cmp, clear_node);
	else
		node->left = dfs_remove_node(key, node->left, cmp, clear_node);
	return (balance_tree(node));
}

void				remove_avl_tree_node(void *key, t_avl_tree *tree)
{
	tree->root = dfs_remove_node(key, tree->root,
		tree->cmp_key, tree->clear_node);
}