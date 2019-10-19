#include "libft.test.h"

void		test_is_nan_l_case1(void)
{
	printf(KYEL "test_is_nan_l_case1\n" KNRM);
	long double		num = (long double)NAN;

	test(
		ft_is_nan_l(num) == 1,
		"ft_is_nan_l : return value"
	);
}

// not nan
void		test_is_nan_l_case2(void)
{
	printf(KYEL "test_is_nan_l_case2\n" KNRM);
	long double		num = 3.14;

	test(
		ft_is_nan_l(num) == 0,
		"ft_is_nan_l : return value"
	);
}
