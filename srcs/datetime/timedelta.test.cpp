#include <gtest/gtest.h>
#include "libft.h"

static time_t	datestr2time(char *str)
{
	struct tm	tm;

	strptime(str, "%Y-%m-%d %H:%M:%S", &tm);
	tm.tm_isdst = -1;
	return (mktime(&tm));
}

TEST(timedelta, ymd_positive)
{
	const char	*s1 = "2020-06-27 00:00:00";
	const char	*s2 = "2006-01-03 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 14);
	ASSERT_EQ(td.month, 5);
	ASSERT_EQ(td.day, 24);
}

TEST(timedelta, day_negative_month_30)
{
	char		s1[20] = "2020-00-03 00:00:00";
	char		s2[20] = "2006-12-27 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;
	const char	*months[] = {"05", "07", "10", "12"};
	int			expected_months[] = {4, 6, 9, 11};

	t2 = datestr2time((char *)s2);

	for (int i=0; i < (int)(sizeof(months) / sizeof(const char *)); i++)
	{
		strncpy(s1 + 5, months[i], 2);
		t1 = datestr2time((char *)s1);

		timedelta(t1, t2, &td);
		ASSERT_EQ(td.year, 13);
		ASSERT_EQ(td.month, expected_months[i]);
		ASSERT_EQ(td.day, 6);
	}
}

TEST(timedelta, day_negative_month_31)
{
	char		s1[20] = "2020-00-03 00:00:00";
	char		s2[20] = "2006-12-27 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;
	const char	*months[] = {"01", "02", "04", "06", "08", "09", "11"};
	int			expected_months[] = {0, 1, 3, 5, 7, 8, 10};

	t2 = datestr2time((char *)s2);

	for (int i=0; i < (int)(sizeof(months) / sizeof(const char *)); i++)
	{
		strncpy(s1 + 5, months[i], 2);
		t1 = datestr2time((char *)s1);

		timedelta(t1, t2, &td);
		ASSERT_EQ(td.year, 13);
		ASSERT_EQ(td.month, expected_months[i]);
		ASSERT_EQ(td.day, 7);
	}
}

TEST(timedelta, month_negative)
{
	const char	*s1 = "2020-02-27 00:00:00";
	const char	*s2 = "2006-06-03 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 13);
	ASSERT_EQ(td.month, 8);
	ASSERT_EQ(td.day, 24);
}

TEST(timedelta, md_negative)
{
	const char	*s1 = "2020-02-03 00:00:00";
	const char	*s2 = "2006-06-25 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 13);
	ASSERT_EQ(td.month, 7);
	ASSERT_EQ(td.day, 9);
}

TEST(timedelta, leap_year_case1)
{
	const char	*s1 = "2020-03-03 00:00:00";
	const char	*s2 = "2006-06-25 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 13);
	ASSERT_EQ(td.month, 8);
	ASSERT_EQ(td.day, 7);
}

TEST(timedelta, leap_year_case2)
{
	const char	*s1 = "2020-03-02 00:00:00";
	const char	*s2 = "2006-07-31 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 13);
	ASSERT_EQ(td.month, 7);
	ASSERT_EQ(td.day, 0);
}

TEST(timedelta, non_leap_year_case1)
{
	const char	*s1 = "2019-03-03 00:00:00";
	const char	*s2 = "2006-06-25 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 12);
	ASSERT_EQ(td.month, 8);
	ASSERT_EQ(td.day, 6);
}

TEST(timedelta, non_leap_year_case2)
{
	const char	*s1 = "2019-03-01 00:00:00";
	const char	*s2 = "2006-06-30 00:00:00";
	time_t		t1;
	time_t		t2;
	t_timedelta	td;

	t1 = datestr2time((char *)s1);
	t2 = datestr2time((char *)s2);

	timedelta(t1, t2, &td);
	ASSERT_EQ(td.year, 12);
	ASSERT_EQ(td.month, 7);
	ASSERT_EQ(td.day, 30);
}
