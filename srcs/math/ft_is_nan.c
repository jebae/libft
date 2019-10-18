#include "libft.h"

int		ft_is_nan(double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0x7ff && (mantissa == 1 ||
		mantissa == 0x8000000000001 || mantissa == 0x8000000000000))
		return (1);
	return (0);
}
