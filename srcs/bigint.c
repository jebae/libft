#include "libft.h"

int		init_bigint(t_bigint *b)
{
	if ((b->digit = ft_memalloc(FT_BIGINT_MEM_SIZE)) == NULL)
		return (FT_FAIL);
	b->length = 0;
	b->size = FT_BIGINT_MEM_SIZE;
	return (FT_SUCCESS);
}

int		realloc_bigint(t_bigint *b)
{
	char	*prev;

	prev = b->digit;
	if ((b->digit = ft_memalloc(FT_BIGINT_MEM_SIZE + b->size))
		== NULL)
		return (FT_FAIL);
	ft_memcpy(b->digit, prev, b->size);
	b->size = FT_BIGINT_MEM_SIZE + b->size;
	ft_memdel(prev);
	return (FT_SUCCESS);
}
