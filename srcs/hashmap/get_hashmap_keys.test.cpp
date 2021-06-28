#include <gtest/gtest.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "libft.h"
#ifdef __cplusplus
}
#endif

const unsigned int	HASH_SIZE = 10;

static int		cmp_key(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b));
}

static void		clear_node(t_tree_node *node)
{
	(void)node;
}

static int		list_has(char *data, t_list *list)
{
	t_list_node	*node;

	node = list->head;
	while (node != NULL)
	{
		if (ft_strcmp((char *)node->data, data) == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

class GetHashmapKeysTest: public ::testing::Test
{
protected:
	t_hashmap	hash;

	void	SetUp(void)
	{
		if (init_hashmap(HASH_SIZE, &hash, cmp_key, clear_node) == -1)
			throw "failed to initialize Hash";
	}

	void	TearDown(void)
	{
		clear_hashmap(&hash);
	}
};

TEST_F(GetHashmapKeysTest, empty)
{
	t_list	key_list;

	// execute
	ASSERT_EQ(get_hashmap_keys(&hash, &key_list), 0);

	// test keys
	ASSERT_EQ(key_list.length, (size_t)0);

	// clear
	clear_list(&key_list);
}

TEST_F(GetHashmapKeysTest, one_exist)
{
	char 	*key = (char *)"key";
	t_list	key_list;

	// set element
	set_hashmap(key, NULL, &hash);

	// execute
	ASSERT_EQ(get_hashmap_keys(&hash, &key_list), 0);

	// test keys
	ASSERT_EQ(key_list.length, (size_t)1);
	ASSERT_EQ(list_has(key, &key_list), 1);

	// clear
	clear_list(&key_list);
}

TEST_F(GetHashmapKeysTest, two_exist)
{
	char 	*key1 = (char *)"key1";
	char 	*key2 = (char *)"key2";
	t_list	key_list;

	// set elements
	set_hashmap(key1, NULL, &hash);
	set_hashmap(key2, NULL, &hash);

	// execute
	ASSERT_EQ(get_hashmap_keys(&hash, &key_list), 0);

	// test keys
	ASSERT_EQ(key_list.length, (size_t)2);
	ASSERT_EQ(list_has(key1, &key_list), 1);
	ASSERT_EQ(list_has(key2, &key_list), 1);

	// clear
	clear_list(&key_list);
}

TEST_F(GetHashmapKeysTest, full_without_hash_conflict)
{
	const char	*keys[HASH_SIZE] = {
		"a", "b", "c", "d", "e",
		"f", "g", "h", "i", "j",
	};
	t_list		key_list;

	// set elements
	for (size_t i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		set_hashmap((char *)keys[i], NULL, &hash);
	}

	// execute
	ASSERT_EQ(get_hashmap_keys(&hash, &key_list), 0);

	// test keys
	ASSERT_EQ(key_list.length, (size_t)10);

	for (size_t i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(list_has((char *)keys[i], &key_list), 1);
	}

	// clear
	clear_list(&key_list);
}

TEST_F(GetHashmapKeysTest, with_hash_conflict)
{
	const char	*keys[HASH_SIZE] = {
		"ab", "ba", "cd", "dc", "e",
		"f", "g", "h", "i", "j",
	};
	t_list		key_list;

	// set elements
	for (size_t i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		set_hashmap((char *)keys[i], NULL, &hash);
	}

	// execute
	ASSERT_EQ(get_hashmap_keys(&hash, &key_list), 0);

	// test keys
	ASSERT_EQ(key_list.length, (size_t)10);

	for (size_t i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(list_has((char *)keys[i], &key_list), 1);
	}

	// clear
	clear_list(&key_list);
}