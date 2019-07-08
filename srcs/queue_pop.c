#include "libft.h"

void		*queue_pop(t_queue *queue)
{
	void		*res;
	t_list		*temp;

	if (queue == NULL)
		return (NULL);
	if (queue->front == NULL)
		return (NULL);
	else
	{
		temp = queue->front->next;
		res = queue->front->content;
		ft_lstdelone(&(queue->front), NULL);
		queue->front = temp;
		if (queue->front == NULL)
			queue->rear = NULL;
	}
	return (res);
}