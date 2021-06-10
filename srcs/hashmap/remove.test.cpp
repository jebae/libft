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

class RemoveHashmapTest: public ::testing::Test
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

TEST_F(RemoveHashmapTest, remove_not_exist)
{
	const char	*keys[HASH_SIZE] = {
		"a", "b", "c", "d", "e",
		"f", "g", "h", "i", "j",
	};
	int			vals[HASH_SIZE] = {
		0, 1, 2, 3, 4,
		5, 6, 7, 8, 9,
	};

	// set
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		set_hashmap((char *)&keys[i], &vals[i], &hash);
	}

	// execute
	remove_hashmap((char *)"not exist", &hash);

	// test
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(&vals[i], get_hashmap((char *)&keys[i], &hash));
	}
}

TEST_F(RemoveHashmapTest, remove_one_node_in_AVL_tree)
{
	const char	*keys[HASH_SIZE] = {
		"a", "b", "c", "d", "e",
		"f", "g", "h", "i", "j",
	};
	int			vals[HASH_SIZE] = {
		0, 1, 2, 3, 4,
		5, 6, 7, 8, 9,
	};

	// set
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		set_hashmap((char *)&keys[i], &vals[i], &hash);
	}

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		remove_hashmap((char *)&keys[i], &hash);
	}

	// test
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(NULL, get_hashmap((char *)&keys[i], &hash));
	}
}

TEST_F(RemoveHashmapTest, remove_multi_node_in_AVL_tree)
{
	const char	*key1 = "name";
	const char	*key2 = "amen";
	const char	*key3 = "nema";
	const char	*val1 = "woody";
	const char	*val2 = "buzz";
	const char	*val3 = "jessy";

	// execute
	set_hashmap((char *)key1, (void *)val1, &hash);
	set_hashmap((char *)key2, (void *)val2, &hash);
	set_hashmap((char *)key3, (void *)val3, &hash);

	// test
	remove_hashmap((char *)key1, &hash);
	ASSERT_EQ(NULL, get_hashmap((char *)key1, &hash));

	remove_hashmap((char *)key2, &hash);
	ASSERT_EQ(NULL, get_hashmap((char *)key2, &hash));

	remove_hashmap((char *)key3, &hash);
	ASSERT_EQ(NULL, get_hashmap((char *)key3, &hash));
}