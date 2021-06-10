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

class SetHashmapTest: public ::testing::Test
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

TEST_F(SetHashmapTest, set_one)
{
	const char	*key = "name";
	const char	*val = "woody";

	// execute
	ASSERT_EQ(set_hashmap((char *)key, (void *)val, &hash), 0);

	// test
	ASSERT_EQ(val, get_hashmap((char *)key, &hash));
}

TEST_F(SetHashmapTest, set_max)
{
	const char	*keys[HASH_SIZE] = {
		"a", "b", "c", "d", "e",
		"f", "g", "h", "i", "j",
	};
	int			vals[HASH_SIZE] = {
		0, 1, 2, 3, 4,
		5, 6, 7, 8, 9,
	};

	// execute
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(set_hashmap((char *)&keys[i], &vals[i], &hash), 0);
	}

	// test
	for (unsigned int i=0; i < sizeof(keys) / sizeof(char *); i++)
	{
		ASSERT_EQ(&vals[i], get_hashmap((char *)&keys[i], &hash));
	}
}

TEST_F(SetHashmapTest, set_duplicate)
{
	const char	*key = "name";
	const char	*prev_val = "woody";
	const char	*new_val = "buzz";

	// test prev
	ASSERT_EQ(set_hashmap((char *)key, (void *)prev_val, &hash), 0);
	ASSERT_EQ(prev_val, get_hashmap((char *)key, &hash));

	// test new
	ASSERT_EQ(set_hashmap((char *)key, (void *)new_val, &hash), 0);
	ASSERT_EQ(new_val, get_hashmap((char *)key, &hash));
}

TEST_F(SetHashmapTest, set_same_hashkey)
{
	const char	*key1 = "name";
	const char	*key2 = "amen";
	const char	*val1 = "woody";
	const char	*val2 = "budha";

	// check if two key's hash key same
	ASSERT_EQ(get_hashmap_key((char *)key1, hash.size),
		get_hashmap_key((char *)key2, hash.size));

	// execute
	ASSERT_EQ(set_hashmap((char *)key1, (void *)val1, &hash), 0);
	ASSERT_EQ(set_hashmap((char *)key2, (void *)val2, &hash), 0);

	// test
	ASSERT_EQ(val1, get_hashmap((char *)key1, &hash));
	ASSERT_EQ(val2, get_hashmap((char *)key2, &hash));
}