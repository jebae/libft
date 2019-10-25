#include "libft.h"

int		ft_utf8_byte_len(char *utf8)
{
	unsigned char	ch;

	if (utf8 == NULL)
		return (0);
	ch = utf8[0];
	if ((ch >> 5) == 0x06)
		return (2);
	else if ((ch >> 4) == 0x0e)
		return (3);
	else if ((ch >> 3) == 0x1e)
		return (4);
	else
		return (1);
}
