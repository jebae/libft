#include <gtest/gtest.h>
#include "libft.h"

TEST(strcat_all, one_str)
{
	char	*concat = strcat_all(1, "foo");

	ASSERT_STREQ(concat, "foo");
	free(concat);
}

TEST(strcat_all, two_str)
{
	char	*concat = strcat_all(2, "foo", "/bar");

	ASSERT_STREQ(concat, "foo/bar");
	free(concat);
}

TEST(strcat_all, more_than_two_str)
{
	char	*concat = strcat_all(3, "foo", "/bar", "/too");

	ASSERT_STREQ(concat, "foo/bar/too");
	free(concat);
}

TEST(strcat_all, n_is_0)
{
	char	*concat = strcat_all(0, "foo", "/bar", "/too");

	ASSERT_EQ((long)concat, NULL);
}
