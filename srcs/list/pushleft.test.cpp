#include <gtest/gtest.h>
#include "libft.h"

class PushLeftListNodeTest: public ::testing::Test {
protected:
	t_list	list;

	virtual void	SetUp() {
		init_list(&list);
	}

	virtual void	TearDown() {
		clear_list(&list);
	}
};

TEST_F(PushLeftListNodeTest, empty)
{
	char	*data = strdup("hello");

	ASSERT_EQ(pushleft_list_node(data, &list), 0);
	ASSERT_EQ((int)list.length, 1);
	ASSERT_EQ((long)list.head, (long)list.tail);
	ASSERT_EQ((long)list.tail->data, (long)data);
	ASSERT_EQ((long)list.tail->next, NULL);
}

TEST_F(PushLeftListNodeTest, one_exist)
{
	char	*data = strdup("hello");

	list.head = (t_list_node *)malloc(sizeof(t_list_node));
	list.head->data = NULL;
	list.head->next = NULL;
	list.tail = list.head;
	list.length = 1;

	ASSERT_EQ(pushleft_list_node(data, &list), 0);
	ASSERT_EQ((int)list.length, 2);
	ASSERT_NE((long)list.head, (long)list.tail);
	ASSERT_EQ((long)list.head->data, (long)data);
	ASSERT_NE((long)list.head->next, NULL);
}

TEST_F(PushLeftListNodeTest, multi_exist)
{
	char	*data = strdup("hello");

	list.head = (t_list_node *)malloc(sizeof(t_list_node));
	list.head->data = NULL;
	list.head->next = (t_list_node *)malloc(sizeof(t_list_node));
	list.head->next->data = NULL;
	list.head->next->next = NULL;
	list.tail = list.head->next;
	list.length = 2;

	ASSERT_EQ(pushleft_list_node(data, &list), 0);
	ASSERT_EQ((int)list.length, 3);
	ASSERT_NE((long)list.head, (long)list.tail);
	ASSERT_EQ((long)list.head->data, (long)data);
	ASSERT_NE((long)list.head->next, NULL);
}

TEST_F(PushLeftListNodeTest, multi_push)
{
	const char	*strs[] = {
		"aa",
		"bb",
		"cc",
		"dd",
		"ee",
	};
	char		*data[5];
	int			len = (int)(sizeof(strs) / sizeof(char *));

	for (int i=0; i < len; i++) {
		data[i] = strdup(strs[i]);
	}

	for (int i=0; i < len; i++) {
		ASSERT_EQ(pushleft_list_node(data[i], &list), 0);
	}

	t_list_node	*node;
	int			i;

	node = list.head;
	for (i=4; node; i--) {
		ASSERT_EQ((long)node->data, (long)data[i]);
		node = node->next;
	}

	ASSERT_EQ(i, -1);
	ASSERT_EQ((int)list.length, 5);
}
