#include "libft.h"

int		ft_is_inf(double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0x7ff && mantissa == 0)
		return (1);
	return (0);
}
