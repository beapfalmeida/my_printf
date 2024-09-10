#include "push_swap.h"

int	count_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i); 
}

void	sort_3(t_stack **a)
{
	if ((*a)->n > (*a)->next->n 
		&& (*a)->next->n > (*a)->next->next->n)
	{
		swap(&a, 1);
		reverse_rotate(&a, 1);
	}
	else if ((*a)->n > (*a)->next->n
		&& (*a)->n > (*a)->next->next->n)
		{
			rotate(&a, 1);
			if ((*a)->n > (*a)->next->n)
				swap(&a, 1);
		}
	else if ((*a)->n > (*a)->next->n
		&& (*a)->n < (*a)->next->next->n)
		swap(&a, 1);
	else if ((*a)->n < (*a)->next->n
		&& (*a)->n > (*a)->next->next->n)
		reverse_rotate(&a, 1);
	else if ((*a)->n < (*a)->next->n
		&& (*a)->n < (*a)->next->next->n)
	{
		reverse_rotate(&a, 1);
		swap(&a, 1);
	}
}

void	sort_4(t_stack **a)
{
	// t_stack *b;
	// t_stack	*temp;

	// temp = *a;
	// b = new_node(0);
	
	// push(a, b, 0);

	// lstclear(b);
	(void)a;
}
void	sort_5(t_stack **a)
{
	(void)a;
}

void	sort_big(t_stack **a)
{
	(void)a;
}
void	sort(t_stack **a)
{
	int	size;

	size = count_stack(*a);
	if (size == 2)
	{
		if ((*a)->n > (*a)->next->n)
			swap(&a, 1);
	}
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a);
	else if (size == 5)
		sort_5(a);
	else if (size > 5)
		sort_big(a);
	lstclear(a);
}