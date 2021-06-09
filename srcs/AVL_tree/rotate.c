#include "libft.h"

static t_tree_node	*rotate_left(t_tree_node *x)
{
	t_tree_node		*y;
	t_tree_node		*t;

	y = x->right;
	if (y == NULL)
		return (NULL);
	t = y->left;
	y->left = x;
	x->right = t;
	update_tree_node_height(x);
	update_tree_node_height(y);
	return (y);
}

static t_tree_node	*rotate_right(t_tree_node *z)
{
	t_tree_node		*y;
	t_tree_node		*t;

	y = z->left;
	if (y == NULL)
		return (NULL);
	t = y->right;
	y->right = z;
	z->left = t;
	update_tree_node_height(z);
	update_tree_node_height(y);
	return (y);
}

static t_tree_node	*rotate_right_left(t_tree_node *node)
{
	if (node == NULL)
		return (NULL);
	node->right = rotate_right(node->right);
	return (rotate_left(node));
}

static t_tree_node	*rotate_left_right(t_tree_node *node)
{
	if (node == NULL)
		return (NULL);
	node->left = rotate_left(node->left);
	return (rotate_right(node));
}

t_tree_node			*balance_tree(t_tree_node *node)
{
	int		balance;

	if (node == NULL)
		return (NULL);
	balance = get_tree_node_balance(node);
	if (balance > 1)
		return ((get_tree_node_balance(node->right) >= 0)
			? rotate_left(node)
			: rotate_right_left(node));
	else if (balance < -1)
		return ((get_tree_node_balance(node->left) <= 0)
			? rotate_right(node)
			: rotate_left_right(node));
	update_tree_node_height(node);
	return (node);
}