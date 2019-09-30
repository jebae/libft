#include "libft.h"

size_t		ft_bit_reverse(size_t x, size_t num_bits)
{
	size_t		copy;
	size_t		rev;
	size_t		i;

	copy = x;
	rev = 0;
	i = 0;
	while (i < num_bits)
	{
		rev <<= 1;
		rev |= (copy & 1);
		copy >>= 1;
		i++;
	}
	i = 0;
	while (i < num_bits)
	{
		x &= ~(1 << i);
		x |= rev & (1 << i);
		i++;
	}
	return (x);
}
