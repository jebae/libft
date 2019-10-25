#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include <stdio.h>
# include <math.h>
# include "libft.h"

/*
** test utils
*/
void	test(int res, const char *msg);

/*
** ft_memnegate
*/
void	test_memnegate_case1(void);
void	test_memnegate_case2(void);

/*
** ft_bit_reverse
*/
void	test_bit_reverse_case1(void);
void	test_bit_reverse_case2(void);
void	test_bit_reverse_case3(void);
void	test_bit_reverse_case4(void);
void	test_bit_reverse_case5(void);

/*
** ft_int_log2
*/
void	test_int_log2_case1(void);
void	test_int_log2_case2(void);
void	test_int_log2_case3(void);

/*
** ft_is_inf
*/
void	test_is_inf_case1(void);
void	test_is_inf_case2(void);
void	test_is_inf_case3(void);

/*
** ft_is_nan
*/
void	test_is_nan_case1(void);
void	test_is_nan_case2(void);

/*
** ft_extract_ldouble
*/
void	test_extract_ldouble_case1(void);
void	test_extract_ldouble_case2(void);

/*
** ft_is_inf_l
*/
void	test_is_inf_l_case1(void);
void	test_is_inf_l_case2(void);

/*
** ft_is_nan
*/
void	test_is_nan_l_case1(void);
void	test_is_nan_l_case2(void);

/*
** ft_to_utf8
*/
void	test_to_utf8_case1(void);
void	test_to_utf8_case2(void);
void	test_to_utf8_case3(void);

/*
** ft_utf8_byte_len
*/
void		test_utf8_byte_len_case1(void);
void		test_utf8_byte_len_case2(void);
void		test_utf8_byte_len_case3(void);

#endif
