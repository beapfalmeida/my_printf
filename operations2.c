#include "push_swap.h"

void	reverse_rotate(t_stack ***stack, int is_a)
{
	t_stack	*last;

	last = find_last(**stack);
	last->next = **stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(**stack)->prev = last;
	**stack = last;
	if (is_a == 1)
		ft_printf("rra\n");
	else if (is_a == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack ****a, t_stack ****b)
{
	reverse_rotate((*a), 2);
	reverse_rotate((*b), 2);
	ft_printf("rrr");
}
