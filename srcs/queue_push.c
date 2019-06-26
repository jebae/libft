#include "libft.h"

void	queue_push(t_queue *queue, void *content, size_t content_size)
{
	if (queue == NULL || content == NULL)
		return ;
	if (queue->rear == NULL)
	{
		queue->rear = ft_lstnew(content, content_size);
		queue->front = queue->rear;
	}
	else
	{
		queue->rear->next = ft_lstnew(content, content_size);
		queue->rear = queue->rear->next;
	}
}