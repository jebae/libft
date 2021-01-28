#include <gtest/gtest.h>
#include "libft.h"

static time_t	datestr2time(char *str)
{
	struct tm	tm;

	strptime(str, "%Y-%m-%d %H:%M:%S", &tm);
	tm.tm_isdst = -1;
	return (mktime(&tm));
}

TEST(get_datetime, valid)
{
	const char	*date = "2019-03-21 11:23:57";
	time_t		t = datestr2time((char *)date);
	t_datetime	dt;

	ASSERT_TRUE(get_datetime(t, &dt));
	ASSERT_EQ(dt.year, 2019);
	ASSERT_EQ(dt.month, 3);
	ASSERT_EQ(dt.day, 21);
	ASSERT_EQ(dt.hour, 11);
	ASSERT_EQ(dt.minute, 23);
	ASSERT_EQ(dt.second, 57);
}
