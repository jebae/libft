#include "libft.test.h"

void		test_extract_ldouble_case1(void)
{
	printf(KYEL "test_extract_ldouble_case1\n" KNRM);
	long double			num;
	short				exponent;
	unsigned long long	mantissa;

	num = 10.625L;
	ft_extract_ldouble(num, &exponent, &mantissa);

	test(
		exponent == 0x4002,
		"ft_extract_ldouble (10.625) : exponent"
	);

	test(
		mantissa == 0xaa00000000000000,
		"ft_extract_ldouble (10.625) : mantissa"
	);
}

void		test_extract_ldouble_case2(void)
{
	printf(KYEL "test_extract_ldouble_case2\n" KNRM);
	long double			num;
	short				exponent;
	unsigned long long	mantissa;

	num = HUGE_VALL;
	ft_extract_ldouble(num, &exponent, &mantissa);

	test(
		exponent == 0x7fff,
		"ft_extract_ldouble (inf) : exponent"
	);

	test(
		mantissa == 0x8000000000000000,
		"ft_extract_ldouble (inf) : mantissa"
	);
}
