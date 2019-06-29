#include "libft.h"

void		set_add(
	t_set *set,
	void *content,
	size_t content_size
)
{
	if (set == NULL || content == NULL)
		return ;
	btree_insert_data(&(set->tree), content, content_size, set->cmpf);
}