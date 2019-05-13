#include "libft.h"

static int	is_whitespace(const char ch)
{
	return (ch == ' ' || (ch >= '\t' && ch <= '\r'));
}

int			ft_hexatoi(const char *str)
{
	unsigned long		res;

	res = 0;
	while (*str != '\0' && is_whitespace(*str))
		str++;
	if (ft_strncmp(str, "0x", 2) != 0)
		return (-1);
	str += 2;
	while (ft_ishexdigit(*str))
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			res = res * 16 + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
			res = res * 16 + (*str - 'A' + 10);
		str++;
	}
	return ((int)res);
}
