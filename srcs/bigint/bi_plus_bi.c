#include "libft.h"

static int		plus(t_bigint *longer, t_bigint *smaller, t_bigint *res)
{
	char			carry;
	char			v;
	unsigned int	i;

	i = 0;
	carry = 0;
	while (i < smaller->length)
	{
		v = smaller->digit[i] + longer->digit[i] + carry;
		if (bi_push_digit(res, v % 10) == FT_FAIL)
			return (FT_FAIL);
		carry = v / 10;
		i++;
	}
	while (i < longer->length)
	{
		v = longer->digit[i] + carry;
		if (bi_push_digit(res, v % 10) == FT_FAIL)
			return (FT_FAIL);
		carry = v / 10;
		i++;
	}
	if (carry != 0 && bi_push_digit(res, carry) == FT_FAIL)
		return (FT_FAIL);
	return (FT_SUCCESS);
}

int				bi_plus_bi(t_bigint *b1, t_bigint *b2, t_bigint *res)
{
	t_bigint	*longer;
	t_bigint	*smaller;

	init_bigint(res);
	if (b1->length > b2->length)
	{
		longer = b1;
		smaller = b2;
	}
	else
	{
		smaller = b1;
		longer = b2;
	}
	return (plus(longer, smaller, res));
}
