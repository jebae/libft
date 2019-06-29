#include "libft.h"

void		set_foreach(t_set *set, void (*f)(void *content))
{
	btree_foreach(set->tree, f);
}