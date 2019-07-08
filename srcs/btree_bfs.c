#include "libft.h"

void		btree_bfs(t_btree *root, void (*f)(void *content))
{
	t_queue		queue;
	t_btree		*poped;

	if (root == NULL)
		return ;
	queue = queue_init();
	queue_push(&queue, root, sizeof(t_btree));
	while (queue.front != NULL)
	{
		poped = queue_pop(&queue);
		queue_push(&queue, poped->left, sizeof(t_btree));
		queue_push(&queue, poped->right, sizeof(t_btree));
		f(poped->content);
		ft_memdel((void **)&poped);
	}
}