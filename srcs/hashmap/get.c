#include "libft.h"

void	*get_hashmap(char *key, t_hashmap *hash)
{
	unsigned int	hashkey;

	hashkey = get_hashmap_key(key, hash->size);
	return (get_avl_tree_val(key, &hash->table[hashkey]));
}