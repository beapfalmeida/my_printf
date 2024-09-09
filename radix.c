#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	if (a->next == NULL)
		exit(1);
	while (a->next)
	{
		if (a->n > a->next->n)
			return 0;
		else if (a->n == a->next->n)
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
			a = a->next;
	}
	return (1);
}

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
#include <stdio.h>
#include <string.h>
void	print_list(t_stack **begin_list)
{
	t_stack *cur = *begin_list;
	while (cur != 0)
	{
		printf("%d\n", (int)(cur->n));
		cur = cur->next;
	}
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
	//print_list(a);
}

void	sort_4(t_stack **a)
{
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
}