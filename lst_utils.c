#include "push_swap.h"

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
	new -> prev = last;
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

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->n = 0;
		free(temp);
	}
}

void	zero_index(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}
