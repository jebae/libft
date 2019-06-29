#include "libft.h"

t_set		set_init(int (*cmpf)(void *, void *))
{
	t_set	set;

	set.tree = NULL;
	set.cmpf = cmpf;
	return (set);
}