#include "libft.h"
#include <stdio.h>

int		ft_is_inf_l(long double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent != 0x7fff)
		return (0);
	if (mantissa == 0 || mantissa == 0x8000000000000000)
		return (1);
	return (0);
}
