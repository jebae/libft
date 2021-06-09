#include <gtest/gtest.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "libft.h"
#ifdef __cplusplus
}
#endif

class RemoveListNodeTest: public ::testing::Test {
protected:
	t_list	list;

	virtual void	SetUp() {
		init_list(&list);
	}

	virtual void	TearDown() {
		clear_list(&list);
	}
};

TEST_F(RemoveListNodeTest, empty)
{
	pop_list_node(0, &list);
	pop_list_node(1, &list);
	pop_list_node(2, &list);
	ASSERT_EQ((int)list.length, 0);
	ASSERT_EQ((long)list.head, NULL);
	ASSERT_EQ((long)list.tail, NULL);
}

TEST_F(RemoveListNodeTest, one_exist)
{
	char	*data = strdup("hello");

	push_list_node(data, &list);

	pop_list_node(0, &list);
	ASSERT_EQ((int)list.length, 0);
	ASSERT_EQ((long)list.head, NULL);
	ASSERT_EQ((long)list.tail, NULL);
}

TEST_F(RemoveListNodeTest, multi_exist)
{
	char	*d1 = strdup("hello");
	char	*d2 = strdup("world");
	char	*d3 = strdup("foo");

	push_list_node(d1, &list);
	push_list_node(d2, &list);
	push_list_node(d3, &list);

	pop_list_node(1, &list);
	ASSERT_EQ((int)list.length, 2);
	ASSERT_EQ((long)list.head->data, (long)d1);
	ASSERT_EQ((long)list.tail->data, (long)d3);

	pop_list_node(1, &list);
	ASSERT_EQ((int)list.length, 1);
	ASSERT_EQ((long)list.head->data, (long)d1);
	ASSERT_EQ((long)list.head, (long)list.tail);

	pop_list_node(0, &list);
	ASSERT_EQ((int)list.length, 0);
	ASSERT_EQ((long)list.head, NULL);
	ASSERT_EQ((long)list.tail, NULL);
}
