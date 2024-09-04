#include "push_swap.h"

void swap(t_stack **a, t_stack *item2, int is_a)
{
	if (a)
	{
		if (*a)
		{
			(*a)->next = item2->next;
			item2->next = *a;
		}
		*a = item2;
	}
	if (is_a == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
void	ss(t_stack **a, t_stack *item2)
{
	swap(a, item2, 1);
	swap(a, item2, 0);
}

void	push(t_stack **a, t_stack **b, int is_a)
{
	t_stack *temp;

	add_front_list(a, *b);
	temp = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->next->prev = *a;
	temp->n = 0;
	free(temp);
	if (is_a == 1)
		printf("pa\n");
	else
		printf("pb\n");
}

