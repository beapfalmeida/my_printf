#include "push_swap.h"

void	add_front_list(t_stack **a, t_stack *new)
{
	if (a)
	{
		if (*a)
			new->next = *a;
		*a = new;
	}
}
void	add_back_list(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = find_last(*lst);
	last -> next = new;
}

t_stack	*find_last(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->n = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
