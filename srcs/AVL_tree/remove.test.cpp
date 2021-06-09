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

class RemoveAVLTreeTest: public ::testing::Test
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

TEST_F(RemoveAVLTreeTest, remove_one_node_exist)
{
	int			key = 42;
	int			val = 24;

	// insert
	ASSERT_EQ(insert_avl_tree_node(&key, &val, &tree), 0);

	// execute
	remove_avl_tree_node(&key, &tree);

	// test structure
	ASSERT_EQ(tree.root, (t_tree_node *)NULL);
}

/*
**    a
**   / \
**  b   c <
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case1)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			a_key = 2;
	int			b_key = 1;
	int			c_key = 3;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;

	a->height = 2;
	b->height = 1;
	c->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;

	// execute
	remove_avl_tree_node(&c_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->right, (t_tree_node *)NULL);
	ASSERT_EQ(a->left, b);
	ASSERT_EQ(b->left, (t_tree_node *)NULL);
	ASSERT_EQ(b->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(b->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**    a
**   / \
**  b   c
**  ^
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case2)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			a_key = 2;
	int			b_key = 1;
	int			c_key = 3;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;

	a->height = 2;
	b->height = 1;
	c->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;

	// execute
	remove_avl_tree_node(&b_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, (t_tree_node *)NULL);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(c->left, (t_tree_node *)NULL);
	ASSERT_EQ(c->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(c->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**    b   c
**   /
**  d <
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case3)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			a_key = 2;
	int			b_key = 1;
	int			c_key = 3;
	int			d_key = 0;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;

	// execute
	remove_avl_tree_node(&d_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, b);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(b->left, (t_tree_node *)NULL);
	ASSERT_EQ(b->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(b->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**    b   c <
**   / \
**  d  e
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case4)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			e_key = 2;
	int			a_key = 3;
	int			c_key = 4;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;
	e->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;

	// execute
	remove_avl_tree_node(&c_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, b);
	ASSERT_EQ(b->left, d);
	ASSERT_EQ(b->right, a);
	ASSERT_EQ(a->left, e);
	ASSERT_EQ(a->right, (t_tree_node *)NULL);
	ASSERT_EQ(d->left, (t_tree_node *)NULL);
	ASSERT_EQ(d->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(b->height, 3);
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(d->height, 1);
	ASSERT_EQ(e->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**    b   c <
**     \
**     d
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case5)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			b_key = 0;
	int			d_key = 1;
	int			a_key = 2;
	int			c_key = 3;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->right = d;

	// execute
	remove_avl_tree_node(&c_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, d);
	ASSERT_EQ(d->left, b);
	ASSERT_EQ(d->right, a);
	ASSERT_EQ(a->right, (t_tree_node *)NULL);
	ASSERT_EQ(a->left, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(d->height, 2);
	ASSERT_EQ(b->height, 1);
	ASSERT_EQ(a->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**    b   c
**   / \
**  d  e <
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case6)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			e_key = 2;
	int			a_key = 3;
	int			c_key = 4;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;
	e->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;

	// execute
	remove_avl_tree_node(&e_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, b);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(b->right, (t_tree_node *)NULL);
	ASSERT_EQ(b->left, d);

	// test height
	ASSERT_EQ(a->height, 3);
	ASSERT_EQ(b->height, 2);
	ASSERT_EQ(c->height, 1);
	ASSERT_EQ(d->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**    b   c
**   / \
**  d  e
**  ^
*/
TEST_F(RemoveAVLTreeTest, remove_leaf_case7)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			e_key = 2;
	int			a_key = 3;
	int			c_key = 4;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;
	e->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;

	// execute
	remove_avl_tree_node(&d_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, b);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(b->left, (t_tree_node *)NULL);
	ASSERT_EQ(b->right, e);

	// test height
	ASSERT_EQ(a->height, 3);
	ASSERT_EQ(b->height, 2);
	ASSERT_EQ(c->height, 1);
	ASSERT_EQ(e->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**  > b   c
**   /
**  d
*/
TEST_F(RemoveAVLTreeTest, remove_one_child_only_case1)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			a_key = 2;
	int			c_key = 3;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;

	// execute
	remove_avl_tree_node(&b_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, d);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(d->left, (t_tree_node *)NULL);
	ASSERT_EQ(d->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(c->height, 1);
	ASSERT_EQ(d->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a
**     / \
**  > b   c
**     \
**     d
*/
TEST_F(RemoveAVLTreeTest, remove_one_child_only_case2)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			b_key = 0;
	int			d_key = 1;
	int			a_key = 2;
	int			c_key = 3;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;

	a->height = 3;
	b->height = 2;
	c->height = 1;
	d->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->right = d;

	// execute
	remove_avl_tree_node(&b_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, d);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(d->left, (t_tree_node *)NULL);
	ASSERT_EQ(d->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(c->height, 1);
	ASSERT_EQ(d->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**         a
**     /       \
**  > b        c
**     \      / \
**     d     e  f
**          /
**         g
*/
TEST_F(RemoveAVLTreeTest, remove_one_child_only_case3)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*f = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*g = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			b_key = 0;
	int			d_key = 1;
	int			a_key = 2;
	int			g_key = 3;
	int			e_key = 4;
	int			c_key = 5;
	int			f_key = 6;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;
	f->key = &f_key;
	g->key = &g_key;

	a->height = 4;
	b->height = 2;
	c->height = 3;
	d->height = 1;
	e->height = 2;
	f->height = 1;
	g->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->right = d;
	c->left = e;
	c->right = f;
	e->left = g;

	// execute
	remove_avl_tree_node(&b_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, e);
	ASSERT_EQ(e->left, a);
	ASSERT_EQ(e->right, c);
	ASSERT_EQ(a->left, d);
	ASSERT_EQ(a->right, g);
	ASSERT_EQ(c->right, f);
	ASSERT_EQ(c->left, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(e->height, 3);
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(c->height, 2);
	ASSERT_EQ(d->height, 1);
	ASSERT_EQ(g->height, 1);
	ASSERT_EQ(f->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a <
**     /
**    b
*/
TEST_F(RemoveAVLTreeTest, remove_one_child_only_case4)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			a_key = 2;
	int			b_key = 1;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;

	a->height = 2;
	b->height = 1;

	// set structure
	tree.root = a;
	a->left = b;

	// execute
	remove_avl_tree_node(&a_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, b);
	ASSERT_EQ(b->right, (t_tree_node *)NULL);
	ASSERT_EQ(b->left, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(b->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**      a <
**     / \
**    b  c
*/
TEST_F(RemoveAVLTreeTest, remove_two_child_case1)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			b_key = 0;
	int			a_key = 1;
	int			c_key = 2;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;

	a->height = 2;
	b->height = 1;
	c->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;

	// execute
	remove_avl_tree_node(&a_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, c);
	ASSERT_EQ(c->right, (t_tree_node *)NULL);
	ASSERT_EQ(c->left, b);

	// test height
	ASSERT_EQ(c->height, 2);
	ASSERT_EQ(b->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**       a
**     /   \
**  > b    c
**   / \  /
**  d  e f
**     \
**     g
*/
TEST_F(RemoveAVLTreeTest, remove_two_child_case2)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*f = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*g = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			e_key = 2;
	int			g_key = 3;
	int			a_key = 4;
	int			f_key = 5;
	int			c_key = 6;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;
	f->key = &f_key;
	g->key = &g_key;

	a->height = 4;
	b->height = 3;
	c->height = 2;
	d->height = 1;
	e->height = 2;
	f->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	e->right = g;

	// execute
	remove_avl_tree_node(&b_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, e);
	ASSERT_EQ(a->right, c);
	ASSERT_EQ(e->left, d);
	ASSERT_EQ(e->right, g);
	ASSERT_EQ(c->left, f);

	// test height
	ASSERT_EQ(a->height, 3);
	ASSERT_EQ(c->height, 2);
	ASSERT_EQ(e->height, 2);
	ASSERT_EQ(d->height, 1);
	ASSERT_EQ(g->height, 1);
	ASSERT_EQ(f->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**           > a
**         /       \
**        b        c
**      /  \     /  \
**     d   e    f   g
*/
TEST_F(RemoveAVLTreeTest, remove_two_child_case3)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*f = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*g = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			d_key = 0;
	int			b_key = 1;
	int			e_key = 2;
	int			a_key = 3;
	int			f_key = 4;
	int			c_key = 5;
	int			g_key = 6;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;
	f->key = &f_key;
	g->key = &g_key;

	a->height = 3;
	b->height = 2;
	c->height = 2;
	d->height = 1;
	e->height = 1;
	f->height = 1;
	g->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	// execute
	remove_avl_tree_node(&a_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, f);
	ASSERT_EQ(f->left, b);
	ASSERT_EQ(f->right, c);
	ASSERT_EQ(b->left, d);
	ASSERT_EQ(b->right, e);
	ASSERT_EQ(c->right, g);
	ASSERT_EQ(c->left, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(f->height, 3);
	ASSERT_EQ(b->height, 2);
	ASSERT_EQ(c->height, 2);
	ASSERT_EQ(e->height, 1);
	ASSERT_EQ(d->height, 1);
	ASSERT_EQ(g->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**           > a
**         /       \
**        b        c
**      /  \     /  \
**     d   e    f   g
**    /        / \   \
**   h        i  j   k
**             \
**             l
*/
TEST_F(RemoveAVLTreeTest, remove_two_child_case4)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*f = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*g = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*h = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*i = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*j = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*k = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*l = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			h_key = 0;
	int			d_key = 1;
	int			b_key = 2;
	int			e_key = 3;
	int			a_key = 4;
	int			i_key = 5;
	int			l_key = 6;
	int			f_key = 7;
	int			j_key = 8;
	int			c_key = 9;
	int			g_key = 10;
	int			k_key = 11;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;
	f->key = &f_key;
	g->key = &g_key;
	h->key = &h_key;
	i->key = &i_key;
	j->key = &j_key;
	k->key = &k_key;
	l->key = &l_key;

	a->height = 5;
	b->height = 3;
	c->height = 4;
	d->height = 2;
	e->height = 1;
	f->height = 3;
	g->height = 2;
	h->height = 1;
	i->height = 2;
	j->height = 1;
	k->height = 1;
	l->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	d->left = h;
	f->left = i;
	f->right = j;
	g->right = k;
	i->right = l;

	// execute
	remove_avl_tree_node(&a_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, i);
	ASSERT_EQ(i->left, b);
	ASSERT_EQ(i->right, c);
	ASSERT_EQ(b->left, d);
	ASSERT_EQ(b->right, e);
	ASSERT_EQ(d->left, h);
	ASSERT_EQ(d->right, (t_tree_node *)NULL);
	ASSERT_EQ(h->left, (t_tree_node *)NULL);
	ASSERT_EQ(h->right, (t_tree_node *)NULL);
	ASSERT_EQ(e->left, (t_tree_node *)NULL);
	ASSERT_EQ(e->right, (t_tree_node *)NULL);
	ASSERT_EQ(c->left, f);
	ASSERT_EQ(c->right, g);
	ASSERT_EQ(f->left, l);
	ASSERT_EQ(f->right, j);
	ASSERT_EQ(g->left, (t_tree_node *)NULL);
	ASSERT_EQ(g->right, k);

	// test height
	ASSERT_EQ(i->height, 4);
	ASSERT_EQ(b->height, 3);
	ASSERT_EQ(c->height, 3);
	ASSERT_EQ(d->height, 2);
	ASSERT_EQ(e->height, 1);
	ASSERT_EQ(f->height, 2);
	ASSERT_EQ(g->height, 2);
	ASSERT_EQ(l->height, 1);
	ASSERT_EQ(j->height, 1);
	ASSERT_EQ(k->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

/*
**           > a
**         /       \
**        b        c
**      /  \     /  \
**     d   e    f   g
**    /        / \   \
**   h        i  j   k
**              /
**             l
*/
TEST_F(RemoveAVLTreeTest, remove_two_child_case5)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*d = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*e = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*f = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*g = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*h = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*i = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*j = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*k = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*l = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			h_key = 0;
	int			d_key = 1;
	int			b_key = 2;
	int			e_key = 3;
	int			a_key = 4;
	int			i_key = 5;
	int			f_key = 6;
	int			l_key = 7;
	int			j_key = 8;
	int			c_key = 9;
	int			g_key = 10;
	int			k_key = 11;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;
	d->key = &d_key;
	e->key = &e_key;
	f->key = &f_key;
	g->key = &g_key;
	h->key = &h_key;
	i->key = &i_key;
	j->key = &j_key;
	k->key = &k_key;
	l->key = &l_key;

	a->height = 5;
	b->height = 3;
	c->height = 4;
	d->height = 2;
	e->height = 1;
	f->height = 3;
	g->height = 2;
	h->height = 1;
	i->height = 1;
	j->height = 2;
	k->height = 1;
	l->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	d->left = h;
	f->left = i;
	f->right = j;
	g->right = k;
	j->left = l;

	// execute
	remove_avl_tree_node(&a_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, i);
	ASSERT_EQ(i->left, b);
	ASSERT_EQ(i->right, c);
	ASSERT_EQ(b->left, d);
	ASSERT_EQ(b->right, e);
	ASSERT_EQ(d->left, h);
	ASSERT_EQ(d->right, (t_tree_node *)NULL);
	ASSERT_EQ(h->left, (t_tree_node *)NULL);
	ASSERT_EQ(h->right, (t_tree_node *)NULL);
	ASSERT_EQ(e->left, (t_tree_node *)NULL);
	ASSERT_EQ(e->right, (t_tree_node *)NULL);
	ASSERT_EQ(c->left, l);
	ASSERT_EQ(c->right, g);
	ASSERT_EQ(l->left, f);
	ASSERT_EQ(l->right, j);
	ASSERT_EQ(g->left, (t_tree_node *)NULL);
	ASSERT_EQ(g->right, k);
	ASSERT_EQ(f->left, (t_tree_node *)NULL);
	ASSERT_EQ(f->right, (t_tree_node *)NULL);
	ASSERT_EQ(j->left, (t_tree_node *)NULL);
	ASSERT_EQ(j->right, (t_tree_node *)NULL);

	// test height
	ASSERT_EQ(i->height, 4);
	ASSERT_EQ(b->height, 3);
	ASSERT_EQ(c->height, 3);
	ASSERT_EQ(d->height, 2);
	ASSERT_EQ(e->height, 1);
	ASSERT_EQ(f->height, 1);
	ASSERT_EQ(g->height, 2);
	ASSERT_EQ(l->height, 2);
	ASSERT_EQ(j->height, 1);
	ASSERT_EQ(k->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}

TEST_F(RemoveAVLTreeTest, remove_not_exist)
{
	t_tree_node	*a = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*b = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	t_tree_node	*c = (t_tree_node *)ft_memalloc(sizeof(t_tree_node));
	int			a_key = 2;
	int			b_key = 1;
	int			c_key = 3;
	int			not_exist_key = 4;

	// set key, height
	a->key = &a_key;
	b->key = &b_key;
	c->key = &c_key;

	a->height = 2;
	b->height = 1;
	c->height = 1;

	// set structure
	tree.root = a;
	a->left = b;
	a->right = c;

	// execute
	remove_avl_tree_node(&not_exist_key, &tree);

	// test structure
	ASSERT_EQ(tree.root, a);
	ASSERT_EQ(a->left, b);
	ASSERT_EQ(a->right, c);

	// test height
	ASSERT_EQ(a->height, 2);
	ASSERT_EQ(b->height, 1);
	ASSERT_EQ(c->height, 1);

	ASSERT_EQ(test_balance(tree.root), 0);
}