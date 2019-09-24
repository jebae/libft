#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include <stdio.h>
# include "libft.h"

/*
** test utils
*/
void	test(int res, const char *msg);

/*
** bigint
*/
void	test_new_bigint_case1(void);
void	test_init_bigint_case1(void);
void	test_expand_bigint_case1(void);
void	test_bi_push_digit_case1(void);
void	test_bi_push_digit_case2(void);
void	test_bi_plus_bi_case1(void);
void	test_bi_mul_bi_case1(void);

#endif
