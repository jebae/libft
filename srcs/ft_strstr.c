#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	return ((char *)boyer_moore(haystack, needle));
}
