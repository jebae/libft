#include "libft.h"

static t_tree_node	*create_node(void *key, void *val)
{
	t_tree_node	*node;

	node = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->val = val;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void			switch_node(
	t_tree_node *dest, t_tree_node *src,
	t_clear_tree_node clear_node)
{
	dest->height = src->height;
	dest->left = src->left;
	dest->right = src->right;
	clear_node(src);
	ft_memdel((void **)&src);
}

static t_tree_node	*insert(
	t_tree_node *new_node, t_tree_node *root,
	t_key_cmp cmp, t_clear_tree_node clear_node)
{
	int		cmp_res;

	if (root == NULL)
		return (new_node);
	cmp_res = cmp(new_node->key, root->key);
	if (cmp_res == 0)
	{
		switch_node(new_node, root, clear_node);
		return (new_node);
	}
	else if (cmp_res > 0)
		root->right = insert(new_node, root->right, cmp, clear_node);
	else
		root->left = insert(new_node, root->left, cmp, clear_node);
	return (balance_tree(root));
}

int					insert_avl_tree_node(
	void *key, void *val, t_avl_tree *tree)
{
	t_tree_node	*new_node;

	new_node = create_node(key, val);
	if (new_node == NULL)
		return (-1);
	tree->root = insert(new_node, tree->root, tree->cmp_key, tree->clear_node);
	return (0);
}