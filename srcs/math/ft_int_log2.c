#include "libft.h"

unsigned int		ft_int_log2(size_t num)
{
	unsigned int		res;

	if (!num)
		return (0);
	res = 0;
	while ((num >>= 1) != 0)
		res++;
	return (res);
}
