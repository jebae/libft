#include "libft.h"

int		ft_iswhitespace(char ch)
{
	return (ch == ' ' || (ch >= 0x09 && ch <= 0x0d));
}
