#include "libft.h"

char	*get_file_content(int fd)
{
	size_t	size;
	char	*content;

	size = lseek(fd, 0, SEEK_END);
	content = (char *)ft_memalloc(size + 1);
	if (content == NULL)
		return (NULL);
	lseek(fd, 0, SEEK_SET);
	read(fd, content, size);
	return (content);
}
