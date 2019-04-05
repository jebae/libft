#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int i, char ch))
{
	char		*new_str;
	size_t		len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[len] = '\0';
	while (len-- > 0)
		new_str[len] = (*f)(len, s[len]);
	return (new_str);
}
