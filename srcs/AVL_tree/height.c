#include "libft.h"

int		get_tree_node_height(t_tree_node *node)
{
	if (node == NULL)
		return (0);
	return node->height;
}

void	update_tree_node_height(t_tree_node *node)
{
	int		left_height;
	int		right_height;

	if (node == NULL)
		return ;
	left_height = get_tree_node_height(node->left);
	right_height = get_tree_node_height(node->right);
	node->height = 1 + ((left_height > right_height)
		? left_height : right_height);
}

int		get_tree_node_balance(t_tree_node *node)
{
	return (get_tree_node_height(node->right)
		- get_tree_node_height(node->left));
}