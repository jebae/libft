#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include <stdio.h>
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

#endif
