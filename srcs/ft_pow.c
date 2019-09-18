#include "libft.h"

long long				ft_powd(long long num, size_t e)
{
	size_t		i;
	long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}

unsigned long long		ft_powud(unsigned long long num, size_t e)
{
	size_t				i;
	unsigned long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}
