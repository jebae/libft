#include "libft.test.h"

void		test_bit_reverse_case1(void)
{
	printf(KYEL "test_bit_reverse_case1\n" KNRM);
	size_t		i;
	size_t		num_bits = 4;
	size_t		res;

	i = 0x08;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0x01,
		"ft_bit_reverse (0x08, 4) : return value"
	);
}

void		test_bit_reverse_case2(void)
{
	printf(KYEL "test_bit_reverse_case2\n" KNRM);
	size_t		i;
	size_t		num_bits = 5;
	size_t		res;

	i = 0x08;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0x02,
		"ft_bit_reverse (0x08, 5) : return value"
	);
}

void		test_bit_reverse_case3(void)
{
	printf(KYEL "test_bit_reverse_case3\n" KNRM);
	size_t		i;
	size_t		num_bits = 4;
	size_t		res;

	i = 0x00;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0x00,
		"ft_bit_reverse (0x00, 4) : return value"
	);
}

void		test_bit_reverse_case4(void)
{
	printf(KYEL "test_bit_reverse_case4\n" KNRM);
	size_t		i;
	size_t		num_bits = 16;
	size_t		res;

	i = 0xb1a2;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0x458d,
		"ft_bit_reverse (0xb1a2, 16) : return value"
	);
}

void		test_bit_reverse_case5(void)
{
	printf(KYEL "test_bit_reverse_case5\n" KNRM);
	size_t		i;
	size_t		num_bits = 11;
	size_t		res;

	i = 0xb1a2;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0xb22c,
		"ft_bit_reverse (0xb1a2, 11) : return value"
	);
}

void		test_bit_reverse_case6(void)
{
	printf(KYEL "test_bit_reverse_case6\n" KNRM);
	size_t		i;
	size_t		num_bits = 11;
	size_t		res;

	i = 0xb1a2;
	res = ft_bit_reverse(i, num_bits);

	test(
		res == 0xb22c,
		"ft_bit_reverse (0xb1a2, 11) : return value"
	);
}
