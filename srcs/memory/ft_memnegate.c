#include "libft.h"

void		ft_memnegate(unsigned char *mem, size_t size)
{
	size_t			i;
	unsigned char	carry;
	unsigned short	added;

	i = 0;
	while (i < size)
	{
		mem[i] = ~(mem[i]);
		i++;
	}
	i = 0;
	carry = 0x01;
	while (i < size)
	{
		added = (unsigned short)(mem[i]) + carry;
		carry = added >> 8;
		mem[i] = (unsigned char)added;
		i++;
	}
}
