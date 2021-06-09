#include <gtest/gtest.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "libft.h"
#ifdef __cplusplus
}
#endif

static int		cmp(void *a, void *b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	return 0;
}

TEST(quick_sort, simple_odd_size)
{
	int	*list[11] = {(int *)3, (int *)7, (int *)2, (int *)8, (int *)5, (int *)4, (int *)9, (int *)1, (int *)0, (int *)10, (int *)6};

	quick_sort((void **)list, 0, 10, cmp);
	for (int i=1; i < 11; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, simple_even_size)
{
	int	*list[10] = {(int *)3, (int *)7, (int *)2, (int *)8, (int *)4, (int *)9, (int *)1, (int *)0, (int *)10, (int *)6};

	quick_sort((void **)list, 0, 9, cmp);
	for (int i=1; i < 10; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, simple_duplicated)
{
	int	*list[10] = {(int *)3, (int *)7, (int *)2, (int *)8, (int *)4, (int *)2, (int *)1, (int *)0, (int *)8, (int *)3};

	quick_sort((void **)list, 0, 9, cmp);
	for (int i=1; i < 10; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, simple_reversed)
{
	int	*list[11] = {(int *)10, (int *)9, (int *)8, (int *)7, (int *)6, (int *)5, (int *)4, (int *)3, (int *)2, (int *)1, (int *)0};

	quick_sort((void **)list, 0, 11, cmp);
	for (int i=1; i < 11; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, simple_ordered)
{
	int	*list[11] = {(int *)0, (int *)1, (int *)2, (int *)3, (int *)4, (int *)5, (int *)6, (int *)7, (int *)8, (int *)9, (int *)10};

	quick_sort((void **)list, 0, 11, cmp);
	for (int i=1; i < 11; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, size_1)
{
	int	*list[1] = {(int *)1};

	quick_sort((void **)list, 0, 0, cmp);
	ASSERT_EQ(list[0], (int *)1);
}

TEST(quick_sort, size_2_ordered)
{
	int	*list[2] = {(int *)1, (int *)2};

	quick_sort((void **)list, 0, 1, cmp);
	ASSERT_EQ(list[0], (int *)1);
	ASSERT_EQ(list[1], (int *)2);
}

TEST(quick_sort, size_2_reversed)
{
	int	*list[2] = {(int *)2, (int *)1};

	quick_sort((void **)list, 0, 1, cmp);
	ASSERT_EQ(list[0], (int *)1);
	ASSERT_EQ(list[1], (int *)2);
}

TEST(quick_sort, size_1000)
{
	srand(time(NULL));
	int	*list[1000];

	for (long long i=0; i < 1000; i++)
	{
		list[i] = (int *)i;
	}

	for (int i=0; i < 1000; i++)
	{
		int a = rand() % 1000;
		int b = rand() % 1000;

		int *temp = list[a];
		list[a] = list[b];
		list[b] = temp;
	}

	quick_sort((void **)list, 0, 1000, cmp);
	for (int i=1; i < 1000; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, size_1000_duplicated)
{
	srand(time(NULL));
	int	*list[1000];

	for (int i=0; i < 1000; i++)
	{
		list[i] = (int *)(long long)(rand() % 300);
	}

	quick_sort((void **)list, 0, 1000, cmp);
	for (int i=1; i < 1000; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}

TEST(quick_sort, size_1000_reversed)
{
	int	*list[1000];

	for (long long i=0; i < 1000; i++)
	{
		list[i] = (int *)(1000 - i);
	}

	quick_sort((void **)list, 0, 1000, cmp);
	for (int i=1; i < 1000; i++)
	{
		ASSERT_GE(list[i], list[i - 1]);
	}
}
