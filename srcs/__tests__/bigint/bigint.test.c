#include "libft.test.h"

void		test_new_bigint_case1(void)
{
	printf(KYEL "test_new_bigint_case1\n" KNRM);
	t_bigint		b;

	new_bigint(&b);

	test(
		b.length == 0,
		"new_bigint : b.length"
	);

	test(
		b.size == FT_BIGINT_MEM_SIZE,
		"new_bigint : b.size"
	);
	free(b.digit);
}

void		test_init_bigint_case1(void)
{
	printf(KYEL "test_init_bigint_case1\n" KNRM);
	t_bigint		b;

	new_bigint(&b);
	b.length = 3;
	init_bigint(&b);

	test(
		b.length == 0,
		"init_bigint : b.length"
	);

	free(b.digit);
}

void		test_expand_bigint_case1(void)
{
	printf(KYEL "test_expand_bigint_case1\n" KNRM);
	t_bigint		b;

	new_bigint(&b);
	for (int i=0; i < FT_BIGINT_MEM_SIZE; i++)
		b.digit[i] = 1;
	expand_bigint(&b);

	test(
		b.length == 0,
		"expand_bigint : b.length"
	);

	test(
		b.size == 2 * FT_BIGINT_MEM_SIZE,
		"expand_bigint : b.size"
	);

	for (int i=0; i < FT_BIGINT_MEM_SIZE; i++)
		test(
			b.digit[i] == 1,
			"expand_bigint : b.digit"
		);
	// check leak
	free(b.digit);
}

void		test_bi_push_digit_case1(void)
{
	printf(KYEL "test_bi_push_digit_case1\n" KNRM);
	t_bigint		b;

	new_bigint(&b);

	bi_push_digit(&b, 9);

	test(
		b.length == 1,
		"bi_push_digit (9) : b.length"
	);

	test(
		b.digit[b.length - 1] == 9,
		"bi_push_digit (9) : b.digit"
	);
	free(b.digit);
}

void		test_bi_push_digit_case2(void)
{
	printf(KYEL "test_bi_push_digit_case2\n" KNRM);
	t_bigint		b;

	new_bigint(&b);

	for (int i=0; i < FT_BIGINT_MEM_SIZE; i++)
		bi_push_digit(&b, 9);

	bi_push_digit(&b, 1);
	test(
		b.length == FT_BIGINT_MEM_SIZE + 1,
		"bi_push_digit (9... 1) : b.length"
	);

	test(
		b.digit[b.length - 1] == 1,
		"bi_push_digit (9... 1) : b.digit"
	);

	test(
		b.size == 2 * FT_BIGINT_MEM_SIZE,
		"bi_push_digit (9... 1) : b.size"
	);
	free(b.digit);
}

void		test_bi_plus_bi_case1(void)
{
	printf(KYEL "test_bi_plus_bi_case1\n" KNRM);
	char			res[17] = {0,};
	t_bigint		b1;
	t_bigint		b2;
	t_bigint		b3;

	new_bigint(&b1);
	new_bigint(&b2);
	new_bigint(&b3);

	// make b1 as 97602318
	bi_push_digit(&b1, 8);
	bi_push_digit(&b1, 1);
	bi_push_digit(&b1, 3);
	bi_push_digit(&b1, 2);
	bi_push_digit(&b1, 0);
	bi_push_digit(&b1, 6);
	bi_push_digit(&b1, 7);
	bi_push_digit(&b1, 9);

	// make b2 as 5710303
	bi_push_digit(&b2, 3);
	bi_push_digit(&b2, 0);
	bi_push_digit(&b2, 3);
	bi_push_digit(&b2, 0);
	bi_push_digit(&b2, 1);
	bi_push_digit(&b2, 7);
	bi_push_digit(&b2, 5);

	bi_plus_bi(&b1, &b2, &b3);
	for (unsigned int i=0; i < b3.size; i++)
		res[i] = b3.digit[b3.size - i - 1] + '0';
	test(
		strcmp(res, "0000000103312621") == 0,
		"bi_plus_bi (97602318 + 5710303) : b3.digit"
	);
	free(b1.digit);
	free(b2.digit);
	free(b3.digit);
}

void		test_bi_mul_bi_case1(void)
{
	printf(KYEL "test_bi_mul_bi_case1\n" KNRM);
	t_bigint		b1;
	t_bigint		b2;
	t_bigint		b3;

	new_bigint(&b1);
	new_bigint(&b2);
	new_bigint(&b3);

	// make b1 as 97602318
	bi_push_digit(&b1, 8);
	bi_push_digit(&b1, 1);
	bi_push_digit(&b1, 3);
	bi_push_digit(&b1, 2);
	bi_push_digit(&b1, 0);
	bi_push_digit(&b1, 6);
	bi_push_digit(&b1, 7);
	bi_push_digit(&b1, 9);

	// make b2 as 5710303
	bi_push_digit(&b2, 3);
	bi_push_digit(&b2, 0);
	bi_push_digit(&b2, 3);
	bi_push_digit(&b2, 0);
	bi_push_digit(&b2, 1);
	bi_push_digit(&b2, 7);
	bi_push_digit(&b2, 5);

	bi_mul_bi(&b1, &b2, &b3);
	for (unsigned int i=0; i < b3.size; i++)
		res[i] = b3.digit[b3.size - i - 1] + '0';
	test(
		strcmp(res, "0557338809282354") == 0,
		"bi_mul_bi (97602318 * 5710303) : b3.digit"
	);
	free(b1.digit);
	free(b2.digit);
	free(b3.digit);
}
