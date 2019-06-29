#include "libft.h"

void		set_foreach_with_arg(
	t_set *set,
	void *arg,
	void (*f)(void *content, void *arg)
)
{
	btree_foreach_with_arg(set->tree, arg, f);
}