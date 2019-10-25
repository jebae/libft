#include "libft.test.h"

// case 가
void		test_to_utf8_case1(void)
{
	printf(KYEL "test_to_utf8_case1\n" KNRM);
	wchar_t			wch = 0xac00;
	char			utf8[4];
	char			expected[4] = { 0xea, 0xb0, 0x80, 0x00 };

	ft_to_utf8(wch, utf8);

	for (int i=0; i < 4; i++)
		test(
			utf8[i] == expected[i],
			"ft_to_utf8 : utf8[i]"
		);
}

// case 😊
void		test_to_utf8_case2(void)
{
	printf(KYEL "test_to_utf8_case2\n" KNRM);
	wchar_t			wch = 0x1f60a;
	char			utf8[4];
	char			expected[4] = { 0xf0, 0x9f, 0x98, 0x8a };

	ft_to_utf8(wch, utf8);

	for (int i=0; i < 4; i++)
		test(
			utf8[i] == expected[i],
			"ft_to_utf8 : utf8[i]"
		);
}

// case j
void		test_to_utf8_case3(void)
{
	printf(KYEL "test_to_utf8_case3\n" KNRM);
	wchar_t			wch = 0x6a;
	char			utf8[4];
	char			expected[4] = { 0x6a, 0x00, 0x00, 0x00 };

	ft_to_utf8(wch, utf8);

	for (int i=0; i < 4; i++)
		test(
			utf8[i] == expected[i],
			"ft_to_utf8 : utf8[i]"
		);
}
