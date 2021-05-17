#include <gtest/gtest.h>
#include "libft.h"

int		cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

class SortListTest: public ::testing::Test
{
protected:
	t_list	list;

	virtual void	SetUp()
	{
		init_list(&list);
	}

	virtual void	TearDown()
	{
		clear_list(&list);
	}
};

TEST_F(SortListTest, reversed)
{
	int	data[10];

	// set data
	for (int i=9; i >= 0; i--)
	{
		data[9-i] = i;
	}

	for (int i=0; i < 10; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)10);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}

TEST_F(SortListTest, ordered)
{
	int	data[10];

	// set data
	for (int i=0; i < 10; i++)
	{
		data[i] = i;
	}

	for (int i=0; i < 10; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)10);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}

TEST_F(SortListTest, unordered_even_length)
{
	int	data[10] = {7, 9, 3, 5, 0, 2, 4, 1, 8, 6};

	// set data
	for (int i=0; i < 10; i++)
	{
		data[i] = i;
	}

	for (int i=0; i < 10; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)10);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}

TEST_F(SortListTest, unordered_odd_length)
{
	int	data[11] = {7, 9, 3, 5, 0, 2, 4, 10, 1, 8, 6};

	// set data
	for (int i=0; i < 11; i++)
	{
		data[i] = i;
	}

	for (int i=0; i < 11; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)11);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}

TEST_F(SortListTest, duplicate)
{
	int	data[11] = {7, 9, 0, 5, 0, 2, 9, 10, 1, 9, 6};

	// set data
	for (int i=0; i < 11; i++)
	{
		data[i] = i;
	}

	for (int i=0; i < 11; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)11);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}

TEST_F(SortListTest, one_node)
{
	// set data
	int		*val = (int *)malloc(sizeof(int));

	*val = 1;
	push_list_node(val, &list);

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)1);
	ASSERT_EQ(*(int *)(list.head->data), 1);
}

TEST_F(SortListTest, two_node)
{
	int	data[2] = {3, 2};

	// set data
	for (int i=0; i < 2; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)2);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
}

TEST_F(SortListTest, two_node_ordered)
{
	int	data[2] = {1, 2};

	// set data
	for (int i=0; i < 2; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)2);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
}

TEST_F(SortListTest, three_node)
{
	int	data[3] = {3, 1, 2};

	// set data
	for (int i=0; i < 3; i++)
	{
		int		*val = (int *)malloc(sizeof(int));

		*val = data[i];
		push_list_node(val, &list);
	}

	// sort
	sort_list(&list, cmp);

	// test
	ASSERT_EQ(list.length, (unsigned long)3);
	t_list_node	*prev = list.head;
	t_list_node	*cur = list.head->next;

	while (cur)
	{
		ASSERT_LE(*(int *)(prev->data), *(int *)(cur->data));
		prev = cur;
		cur = cur->next;
	}
}