#include "push_swap.h"

void swap(t_stack ***stack, int is_a)
{
	t_stack	*first;

	first = **stack;
	**stack = (**stack)->next;
	first->prev = first->next;
	first->next = first->next->next;
	(**stack)->prev = NULL;
	(**stack)->next = first;
	first->next->prev = first;
	if (is_a == 1)
		printf("sa\n");
	else if (is_a == 0)
		printf("sb\n");
}
void	ss(t_stack ****a, t_stack ****b)
{
	swap(*a, 2);
	swap(*b, 2);
	ft_printf("ss\n");
}

void	push(t_stack ***src, t_stack ***dest, int is_a)
{
	t_stack **start;

	start = *src;
	**src = (**src)->next;
	// se a lista src so tivesse 1 elmento:
	if (**src)
		(**src)->prev = NULL;
	if (**dest)
	{
		(*start)->next = **dest;
		(*start)->next->prev = *start;
	}
	else
		(*start)->next = NULL;
	**dest = *start;
	if (is_a == 1)
		ft_printf("pa\n");
	else if (is_a == 0)
		ft_printf("pb\n");
}

void	rotate(t_stack ***stack, int is_a)
{
	t_stack	*last;

	last = find_last(**stack);
	(**stack)->prev = last;
	last->next = **stack;
	**stack = (**stack)->next;
	last->next->next = NULL;
	(**stack)->prev = NULL;
	if (is_a == 1)
		ft_printf("ra\n");
	else if (is_a == 0)
		ft_printf("rb\n");
}

void	rr(t_stack	****a,  t_stack ****b)
{
	rotate(*a, 2);
	rotate(*b, 2);
	ft_printf("rr\n");
}