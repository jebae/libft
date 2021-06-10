#include "libft.h"

unsigned int	get_hashmap_key(char *key, unsigned int size)
{
	unsigned int	sum;
	size_t			i;

	sum = 0;
	i = 0;
	while (key[i] != '\0')
	{
		sum += (unsigned int)key[i];
		i++;
	}
	return (sum % size);
}