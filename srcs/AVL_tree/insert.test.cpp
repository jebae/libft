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

class InsertAVLTreeTest: public ::testing::Test
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
			printf("key: %d height: %d\n", *(int *)node->key, node->height);
		if (node->left)
			printf("left: %d\n", *(int *)node->left->key);
		if (node->right)
			printf("right: %d\n", *(int *)node->right->key);

		dfs(node->left);
		dfs(node->right);
	}
};

TEST_F(InsertAVLTreeTest, insert_to_empty)
{
	int			key = 42;
	int			val = 24;
	int			*val_ptr;
	t_tree_node	*node;

	// execute
	ASSERT_EQ(insert_avl_tree_node(&key, &val, &tree), 0);

	// test val
	val_ptr = (int *)get_avl_tree_val(&key, &tree);
	ASSERT_EQ(*val_ptr, val);

	// test height
	node = tree.root;
	ASSERT_EQ(node->height, 1);
}

TEST_F(InsertAVLTreeTest, insert_to_one_exist)
{
	int			keys[] = {42, 2};
	int			vals[] = {0, 1};
	int			*val_ptr;

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		ASSERT_EQ(insert_avl_tree_node(&keys[i], &vals[i], &tree), 0);
	}

	// test val
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		val_ptr = (int *)get_avl_tree_val(&keys[i], &tree);
		ASSERT_EQ(*val_ptr, vals[i]);
	}

	// test balance
	ASSERT_EQ(test_balance(tree.root), 0);
}

TEST_F(InsertAVLTreeTest, insert_many)
{
	int			keys[] = {42, 2, 3, 5, 6, 0, 1, 45, 22, -4};
	int			vals[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			*val_ptr;

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		ASSERT_EQ(insert_avl_tree_node(&keys[i], &vals[i], &tree), 0);
	}

	// test val
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		val_ptr = (int *)get_avl_tree_val(&keys[i], &tree);
		ASSERT_EQ(*val_ptr, vals[i]);
	}

	// test balance
	ASSERT_EQ(test_balance(tree.root), 0);
}

TEST_F(InsertAVLTreeTest, insert_by_ordered)
{
	int			keys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			vals[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			*val_ptr;

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		ASSERT_EQ(insert_avl_tree_node(&keys[i], &vals[i], &tree), 0);
	}

	// test val
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		val_ptr = (int *)get_avl_tree_val(&keys[i], &tree);
		ASSERT_EQ(*val_ptr, vals[i]);
	}

	// test balance
	ASSERT_EQ(test_balance(tree.root), 0);
}

TEST_F(InsertAVLTreeTest, insert_by_reverse_ordered)
{
	int			keys[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int			vals[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			*val_ptr;

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		ASSERT_EQ(insert_avl_tree_node(&keys[i], &vals[i], &tree), 0);
	}

	// test val
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		val_ptr = (int *)get_avl_tree_val(&keys[i], &tree);
		ASSERT_EQ(*val_ptr, vals[i]);
	}

	// test balance
	ASSERT_EQ(test_balance(tree.root), 0);
}

TEST_F(InsertAVLTreeTest, key_already_exist)
{
	int			keys[] = {42, 2, 3, 5, 6, 0, 1, 45, 22, -4};
	int			vals[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			*val_ptr;

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(int); i++)
	{
		ASSERT_EQ(insert_avl_tree_node(&keys[i], &vals[i], &tree), 0);
	}

	int		new_val = -42;

	ASSERT_EQ(insert_avl_tree_node(&keys[0], &new_val, &tree), 0);

	// test val
	val_ptr = (int *)get_avl_tree_val(&keys[0], &tree);
	ASSERT_EQ(*val_ptr, new_val);

	for (unsigned int i=1; i < sizeof(keys) / sizeof(int); i++)
	{
		val_ptr = (int *)get_avl_tree_val(&keys[i], &tree);
		ASSERT_EQ(*val_ptr, vals[i]);
	}

	// test balance
	ASSERT_EQ(test_balance(tree.root), 0);
}