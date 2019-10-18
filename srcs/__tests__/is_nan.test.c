#include "libft.test.h"

void		test_is_nan_case1(void)
{
	printf(KYEL "test_is_nan_case1\n" KNRM);
	double		num = NAN;

	test(
		ft_is_nan(num) == 1,
		"ft_is_nan : return value"
	);
}

// not nan
void		test_is_nan_case2(void)
{
	printf(KYEL "test_is_nan_case2\n" KNRM);
	double		num = 3.14;

	test(
		ft_is_nan(num) == 0,
		"ft_is_nan : return value"
	);
}
