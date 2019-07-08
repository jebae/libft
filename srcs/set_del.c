#include "libft.h"

static void		del(void *content)
{
	ft_memdel((void **)&content);
}

void			set_del(t_set *set)
{
	btree_del(&(set->tree), &del);
}