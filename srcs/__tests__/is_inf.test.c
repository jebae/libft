#include "libft.test.h"

void		test_is_inf_case1(void)
{
	printf(KYEL "test_is_inf_case1\n" KNRM);
	double		num = INFINITY;

	test(
		ft_is_inf(num) == 1,
		"ft_is_inf : return value"
	);
}

// not inf
void		test_is_inf_case2(void)
{
	printf(KYEL "test_is_inf_case2\n" KNRM);
	double		num = 3.14;

	test(
		ft_is_inf(num) == 0,
		"ft_is_inf : return value"
	);
}

// -inf
void		test_is_inf_case3(void)
{
	printf(KYEL "test_is_inf_case3\n" KNRM);
	double		num = -INFINITY;

	test(
		ft_is_inf(num) == 1,
		"ft_is_inf : return value"
	);
}
