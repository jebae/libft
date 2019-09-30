#include "libft.test.h"

void		test_memnegate_case1(void)
{
	printf(KYEL "test_memnegate_case1\n" KNRM);
	unsigned char	*mem;

	mem = ft_memalloc(2);
	mem[0] = 0xff;
	mem[1] = 0xff;
	ft_memnegate(mem, 2);

	test(
		mem[0] == 0x01,
		"ft_memnegate (0xffff) : mem[0]"
	);

	test(
		mem[1] == 0x00,
		"ft_memnegate (0xffff) : mem[1]"
	);

	free(mem);
}

void		test_memnegate_case2(void)
{
	printf(KYEL "test_memnegate_case2\n" KNRM);
	unsigned char	*mem;

	mem = ft_memalloc(2);

	mem[0] = 0xff;
	mem[1] = 0xff;
	ft_memnegate(mem, 1);

	test(
		mem[0] == 0x01,
		"ft_memnegate (0xffff) only 1byte : mem[0]"
	);

	test(
		mem[1] == 0xff,
		"ft_memnegate (0xffff) only 1byte : mem[1]"
	);

	free(mem);
}
