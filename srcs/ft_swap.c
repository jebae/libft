#include "libft.h"

void		ft_swap(void *p1, void *p2, size_t size)
{
	void	*temp;

	temp = ft_memalloc(size);
	ft_memcpy(temp, p1, size);
	ft_memcpy(p1, p2, size);
	ft_memcpy(p2, temp, size);
	ft_memdel(&temp);
}
