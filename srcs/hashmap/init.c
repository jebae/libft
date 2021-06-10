#include "libft.h"

int		init_hashmap(
	unsigned int size, t_hashmap *hash,
	t_key_cmp cmp_key, t_clear_tree_node clear_node)
{
	unsigned	i;

	hash->size = size;
	hash->table = ft_memalloc(sizeof(t_avl_tree) * size);
	if (hash->table == NULL)
		return (-1);
	i = 0;
	while (i < size)
		init_avl_tree(&hash->table[i++], cmp_key, clear_node);
	return (0);
}