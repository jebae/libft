#include "libft.h"

int		init_bigint(t_bigint *b)
{
	if ((b->digit = ft_memalloc(FT_BIGINT_MEM_SIZE)) == NULL)
		return (FT_FAIL);
	b->length = -1;
	return (FT_SUCCESS);
}
