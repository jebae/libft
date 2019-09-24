#include "libft.test.h"

int		main(void)
{
	// bigint
	test_new_bigint_case1();
	test_init_bigint_case1();
	test_expand_bigint_case1();
	test_bi_push_digit_case1();
	test_bi_push_digit_case2();
	test_bi_plus_bi_case1();
	test_bi_mul_bi_case1();
	return (0);
}
