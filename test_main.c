#include "libft.test.h"

int		main(void)
{
	// ft_memnegate
	test_memnegate_case1();
	test_memnegate_case2();

	// ft_bit_reverse
	test_bit_reverse_case1();
	test_bit_reverse_case2();
	test_bit_reverse_case3();
	test_bit_reverse_case4();
	test_bit_reverse_case5();

	// ft_int_log2
	test_int_log2_case1();
	test_int_log2_case2();
	test_int_log2_case3();

	// ft_is_inf
	test_is_inf_case1();
	test_is_inf_case2();
	test_is_inf_case3();

	// ft_is_nan
	test_is_nan_case1();
	test_is_nan_case2();

	// ft_extract_ldouble
	test_extract_ldouble_case1();
	test_extract_ldouble_case2();

	// ft_is_inf_l
	test_is_inf_l_case1();
	test_is_inf_l_case2();

	// ft_is_nan_l
	test_is_nan_l_case1();
	test_is_nan_l_case2();

	// ft_to_utf8
	test_to_utf8_case1();
	test_to_utf8_case2();
	test_to_utf8_case3();

	// ft_utf8_byte_len
	test_utf8_byte_len_case1();
	test_utf8_byte_len_case2();
	test_utf8_byte_len_case3();
}
