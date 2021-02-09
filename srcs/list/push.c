#include "libft.h"

int		push_list_node(void *data, t_list *list)
{
	t_list_node	*node;

	node = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	if (node == NULL)
		return (-1);
	node->data = data;
	node->next = NULL;
	if (list->head == NULL)
		list->head = node;
	if (list->tail != NULL)
		list->tail->next = node;
	list->tail = node;
	list->length++;
	return (0);
}
