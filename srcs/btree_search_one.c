#include "libft.h"

void		*btree_search_one(
	t_btree *root,
	void *p_data,
	int (*cmpf)(void *, void *)
)
{
	void	*res;

	if (root == NULL || p_data == NULL || cmpf == NULL)
		return (NULL);
	res = btree_search_one(root->left, p_data, cmpf);
	if (res != NULL)
		return (res);
	if (cmpf(root->content, p_data) == 1)
		return (root->content);
	return (btree_search_one(root->right, p_data, cmpf));
}