#include "libft.h"

t_queue		queue_init(void)
{
	t_queue		queue;

	queue.front = NULL;
	queue.rear = NULL;
	return (queue);
}