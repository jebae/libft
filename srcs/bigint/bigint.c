#include "libft.h"

int		new_bigint(t_bigint *b)
{
	if ((b->digit = ft_memalloc(FT_BIGINT_MEM_SIZE)) == NULL)
		return (FT_FAIL);
	b->length = 0;
	b->size = FT_BIGINT_MEM_SIZE;
	return (FT_SUCCESS);
}

void	init_bigint(t_bigint *b)
{
	b->length = 0;
}

int		expand_bigint(t_bigint *b)
{
	char	*temp;

	if ((temp = ft_memalloc(FT_BIGINT_MEM_SIZE + b->size)) == NULL)
		return (FT_FAIL);
	ft_memcpy(temp, b->digit, b->size);
	ft_memdel((void **)&(b->digit));
	b->digit = temp;
	b->size += FT_BIGINT_MEM_SIZE;
	return (FT_SUCCESS);
}

int		bi_push_digit(t_bigint *b, char value)
{
	if (b->length == b->size)
	{
		if (expand_bigint(b) == FT_FAIL)
			return (FT_FAIL);
	}
	b->digit[b->length] = value;
	(b->length)++;
	return (FT_SUCCESS);
}
