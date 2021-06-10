#include "libft.h"

void	clear_hashmap(t_hashmap *hash)
{
	unsigned int	i;

	i = 0;
	while (i < hash->size)
		clear_avl_tree(&hash->table[i++]);
	ft_memdel((void **)&hash->table);
}

void	remove_hashmap(char *key, t_hashmap *hash)
{
	unsigned int	hashkey;

	hashkey = get_hashmap_key(key, hash->size);
	return (remove_avl_tree_node(key, &hash->table[hashkey]));
}