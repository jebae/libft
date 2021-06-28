#include "libft.h"

unsigned int	get_hashmap_key(char *key, unsigned int size)
{
	unsigned int	sum;
	size_t			i;

	sum = 0;
	i = 0;
	while (key[i] != '\0')
	{
		sum += (unsigned int)key[i];
		i++;
	}
	return (sum % size);
}

static int		add_key_from_tree(t_tree_node *node, t_list *keys)
{
	char	*key;

	if (node->left)
		if (add_key_from_tree(node->left, keys) == -1)
			return (-1);
	key = ft_strdup(node->key);
	if (key == NULL)
		return (-1);
	if (push_list_node((void *)key, keys) == -1)
	{
		ft_memdel((void **)&key);
		return (-1);
	}
	if (node->right)
		if (add_key_from_tree(node->right, keys) == -1)
			return (-1);
	return (0);
}

int				get_hashmap_keys(t_hashmap *hash, t_list *keys)
{
	unsigned int	i;

	init_list(keys);
	i = 0;
	while (i < hash->size)
	{
		if (hash->table[i].root)
		{
			if (add_key_from_tree(hash->table[i].root, keys) == -1)
			{
				clear_list(keys);
				return (-1);
			}
		}
		i++;
	}
	return (0);
}