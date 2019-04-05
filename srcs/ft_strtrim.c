#include "libft.h"


// 오늘은 여기까지
char	*ft_strtrim(const char *s)
{
	char	*end;
	char	*trim;

	if (s == NULL)
		return (NULL);
	end = (char *)s;
	while (*end != ' ' && *end != '\n' && *end != '\t' && *end != '\0')
		end++;
	trim = (char *)malloc(sizeof(char) * (end - s + 1));
	if (trim == NULL)
		return (NULL);
	ft_strncpy(trim, s, end - s);
	trim[end - s] = '\0';
	return (trim);
}
