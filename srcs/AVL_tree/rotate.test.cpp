#include <gtest/gtest.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "libft.h"
#ifdef __cplusplus
}
#endif

static int		cmp_key(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

static void		clear_node(t_tree_node *node)
{
	(void)node;
}

class RotateAVLTreeTest: public ::testing::Test
{
protected:
	t_avl_tree	tree;

	void	SetUp(void)
	{
		init_avl_tree(&tree, cmp_key, clear_node);
	}

	void	TearDown(void)
	{
		clear_avl_tree(&tree);
	}

	int		test_balance(t_tree_node *node)
	{
		int	balance;

		if (node == NULL)
			return (0);
		balance = get_tree_node_balance(node);
		if (balance > 1 || balance < -1)
			return (-1);
		if (test_balance(node->left) == -1)
			return (-1);
		if (test_balance(node->right) == -1)
			return (-1);
		return (0);
	}

	void	dfs(t_tree_node *node)
	{
		if (node == NULL)
			return ;

		if (node->key)
			printf("key: %d\n", *(int *)node->key);
		if (node->left && node->left->key)
			printf("left: %d\n", *(int *)node->left->key);
		if (node->right && node->right->key)
			printf("right: %d\n", *(int *)node->right->key);

		dfs(node->left);
		dfs(node->right);
	}
};

TEST_F(RotateAVLTreeTest, balance_tree_by_rotate_left)
{
	int		keys[] = {3, 4, 5, 6};

	t_tree_node	*x = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*inserted = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*x_left = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y_left = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));

	// set x
	x->key = &keys[0];
	x->left = x_left;
	x->right = y;
	x_left->height = 1;

	// set y
	y->key = &keys[1];
	y->left = y_left;
	y->right = z;
	y->height = 3;
	y_left->height = 1;

	// set z
	z->key = &keys[2];
	z->right = inserted;
	z->height = 2;

	// set inserted
	inserted->key = &keys[3];
	inserted->height = 1;

	// execute
	tree.root = balance_tree(x);

	// test structure
	ASSERT_EQ(tree.root, y);
	ASSERT_EQ(tree.root->left, x);
	ASSERT_EQ(x->left, x_left);
	ASSERT_EQ(x->right, y_left);
	ASSERT_EQ(tree.root->right, z);
	ASSERT_EQ(z->right, inserted);

	// test height
	ASSERT_EQ(tree.root->height, 3);
	ASSERT_EQ(x->height, 2);
	ASSERT_EQ(z->height, 2);
	ASSERT_EQ(x_left->height, 1);
	ASSERT_EQ(y_left->height, 1);
}

TEST_F(RotateAVLTreeTest, balance_tree_by_rotate_right)
{
	int		keys[] = {6, 5, 4, 3};

	t_tree_node	*x = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*inserted = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z_right = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y_right = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));

	// set z
	z->key = &keys[0];
	z->left = y;
	z->right = z_right;
	z_right->height = 1;

	// set y
	y->key = &keys[1];
	y->left = x;
	y->right = y_right;
	y->height = 3;
	y_right->height = 1;

	// set x
	x->key = &keys[2];
	x->left = inserted;
	x->height = 2;

	// set inserted
	inserted->key = &keys[3];
	inserted->height = 1;

	// execute
	tree.root = balance_tree(z);

	// test structure
	ASSERT_EQ(tree.root, y);
	ASSERT_EQ(tree.root->right, z);
	ASSERT_EQ(z->right, z_right);
	ASSERT_EQ(z->left, y_right);
	ASSERT_EQ(tree.root->left, x);
	ASSERT_EQ(x->left, inserted);

	// test height
	ASSERT_EQ(tree.root->height, 3);
	ASSERT_EQ(x->height, 2);
	ASSERT_EQ(z->height, 2);
	ASSERT_EQ(z_right->height, 1);
	ASSERT_EQ(y_right->height, 1);
}

TEST_F(RotateAVLTreeTest, balance_tree_by_rotate_right_left)
{
	int		keys[] = {3, 6, 4, 5};

	t_tree_node	*x = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*inserted = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*x_left = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y_left = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));

	// set x
	x->key = &keys[0];
	x->left = x_left;
	x->right = z;
	x_left->height = 1;

	// set z
	z->key = &keys[1];
	z->left = y;
	z->height = 3;

	// set y
	y->key = &keys[2];
	y->right = inserted;
	y->left = y_left;
	y->height = 2;
	y_left->height = 1;

	// set inserted
	inserted->key = &keys[3];
	inserted->height = 1;

	// execute
	tree.root = balance_tree(x);

	// test structure
	ASSERT_EQ(tree.root, y);
	ASSERT_EQ(tree.root->left, x);
	ASSERT_EQ(x->left, x_left);
	ASSERT_EQ(x->right, y_left);
	ASSERT_EQ(tree.root->right, z);
	ASSERT_EQ(z->left, inserted);

	// test height
	ASSERT_EQ(tree.root->height, 3);
	ASSERT_EQ(x->height, 2);
	ASSERT_EQ(z->height, 2);
	ASSERT_EQ(x_left->height, 1);
	ASSERT_EQ(y_left->height, 1);
}

TEST_F(RotateAVLTreeTest, balance_tree_by_rotate_left_right)
{
	int		keys[] = {6, 3, 5, 4};

	t_tree_node	*x = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*inserted = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*z_right = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*y_right = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));

	// set z
	z->key = &keys[0];
	z->right = z_right;
	z->left = x;
	z_right->height = 1;

	// set x
	x->key = &keys[1];
	x->right = y;
	x->height = 3;

	// set y
	y->key = &keys[2];
	y->right = y_right;
	y->left = inserted;
	y->height = 2;
	y_right->height = 1;

	// set inserted
	inserted->key = &keys[3];
	inserted->height = 1;

	// execute
	tree.root = balance_tree(z);

	// test structure
	ASSERT_EQ(tree.root, y);
	ASSERT_EQ(tree.root->left, x);
	ASSERT_EQ(x->right, inserted);
	ASSERT_EQ(tree.root->right, z);
	ASSERT_EQ(z->left, y_right);
	ASSERT_EQ(z->right, z_right);

	// test height
	ASSERT_EQ(tree.root->height, 3);
	ASSERT_EQ(x->height, 2);
	ASSERT_EQ(z->height, 2);
	ASSERT_EQ(z_right->height, 1);
	ASSERT_EQ(y_right->height, 1);
}