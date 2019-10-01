#include "libft.test.h"

void		test_int_log2_case1(void)
{
	printf(KYEL "test_int_log2_case1\n" KNRM);
	size_t			i;
	unsigned int	res;

	i = 0x08;
	res = ft_int_log2(i);

	test(
		res == 3,
		"ft_int_log2 (0x08) : return value"
	);
}

void		test_int_log2_case2(void)
{
	printf(KYEL "test_int_log2_case2\n" KNRM);
	size_t			i;
	unsigned int	res;

	i = 0x100000001;
	res = ft_int_log2(i);

	test(
		res == 32,
		"ft_int_log2 (0x100000001) : return value"
	);
}

void		test_int_log2_case3(void)
{
	printf(KYEL "test_int_log2_case3\n" KNRM);
	size_t			i;
	unsigned int	res;

	i = 0xffffffff;
	res = ft_int_log2(i);

	test(
		res == 31,
		"ft_int_log2 (0xffffffff) : return value"
	);
}
