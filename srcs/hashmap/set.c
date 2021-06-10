#include "libft.h"

int		set_hashmap(char *key, void *val, t_hashmap *hash)
{
	unsigned int	hashkey;

	hashkey = get_hashmap_key(key, hash->size);
	return (insert_avl_tree_node(key, val, &hash->table[hashkey]));
}