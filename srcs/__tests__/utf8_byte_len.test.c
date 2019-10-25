#include "libft.test.h"

// case 가
void		test_utf8_byte_len_case1(void)
{
	printf(KYEL "test_utf8_byte_len_case1\n" KNRM);
	char			utf8[4] = { 0xea, 0xb0, 0x80, 0x00 };

	test(
		ft_utf8_byte_len(utf8) == 3,
		"ft_utf8_byte_len : return value"
	);
}

// case 📱
void		test_utf8_byte_len_case2(void)
{
	printf(KYEL "test_utf8_byte_len_case2\n" KNRM);
	char			utf8[4] = { 0xf0, 0x9f, 0x93, 0xb1 };

	test(
		ft_utf8_byte_len(utf8) == 4,
		"ft_utf8_byte_len : return value"
	);
}

// case a
void		test_utf8_byte_len_case3(void)
{
	printf(KYEL "test_utf8_byte_len_case3\n" KNRM);
	char			utf8[4] = { 0x61, 0x00, 0x00, 0x00 };

	test(
		ft_utf8_byte_len(utf8) == 1,
		"ft_utf8_byte_len : return value"
	);
}
