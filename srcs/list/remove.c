#include "libft.h"

void	pop_list_node(size_t idx, t_list *list)
{
	t_list_node	*node;
	t_list_node	*prev;

	prev = NULL;
	node = list->head;
	while (idx && node)
	{
		idx--;
		prev = node;
		node = node->next;
	}
	if (idx > 0 || node == NULL)
		return ;
	if (prev == NULL)
		list->head = node->next;
	else
		prev->next = node->next;
	if (node == list->tail)
		list->tail = prev;
	ft_memdel((void **)&node->data);
	ft_memdel((void **)&node);
	list->length--;
}

void	clear_list(t_list *list)
{
	t_list_node	*node;
	t_list_node	*next;

	node = list->head;
	while (node)
	{
		next = node->next;
		ft_memdel((void **)&node->data);
		ft_memdel((void **)&node);
		node = next;
	}
}
