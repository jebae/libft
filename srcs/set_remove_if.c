#include "libft.h"

void		set_remove_if(
	t_set *set,
	void *p_data,
	int (*cmpf)(void *, void *)
)
{
	if (set == NULL || p_data == NULL || cmpf == NULL)
		return ;
	btree_remove_if(&(set->tree), p_data, cmpf);
}