#include "libft.h"

static t_list_node	*merge(t_list_node *a, t_list_node *b, t_sort_cmp cmp)
{
	t_list_node	dumb;
	t_list_node	*cur;

	cur = &dumb;
	while (a != NULL && b != NULL)
	{
		if (cmp(a->data, b->data) <= 0)
		{
			cur->next = a;
			a = a->next;
		}
		else
		{
			cur->next = b;
			b = b->next;
		}
		cur = cur->next;
	}
	cur->next = (a != NULL) ? a : b;
	return (dumb.next);
}

static t_list_node	*sort(t_list_node *node, t_sort_cmp cmp)
{
	t_list_node	dumb;
	t_list_node	*slow;
	t_list_node	*fast;
	t_list_node	*right;

	if (node == NULL || node->next == NULL)
		return (node);
	dumb.next = node;
	slow = &dumb;
	fast = node;
	while (fast)
	{
		fast = fast->next;
		if (fast)
			fast = fast->next;
		slow = slow->next;
	}
	right = slow->next;
	slow->next = NULL;
	slow = sort(node, cmp);
	right = sort(right, cmp);
	return (merge(slow, right, cmp));
}

void				sort_list(t_list *list, t_sort_cmp cmp)
{
	t_list_node	*tail;

	if (list->length == 0)
		return ;
	list->head = sort(list->head, cmp);
	tail = list->head;
	while (tail->next)
		tail = tail->next;
	list->tail = tail;
}