#include "libft.h"

void		ft_extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa
)
{
	if (exponent == NULL || mantissa == NULL)
		return ;
	*mantissa = *((unsigned long long *)&num);
	*exponent = (*mantissa >> 52) & 0x7ff;
	*mantissa &= 0xfffffffffffff;
}
