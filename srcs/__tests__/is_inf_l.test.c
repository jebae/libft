#include "libft.test.h"

void		test_is_inf_l_case1(void)
{
	printf(KYEL "test_is_inf_l_case1\n" KNRM);
	long double		num = HUGE_VALL;

	test(
		ft_is_inf_l(num) == 1,
		"ft_is_inf_l : return value"
	);
}

void		test_is_inf_l_case2(void)
{
	printf(KYEL "test_is_inf_l_case2\n" KNRM);
	long double		num = 3.14;

	test(
		ft_is_inf_l(num) == 0,
		"ft_is_inf_l : return value"
	);
}
