#include "push_swap.h"

int	has_duplicates(t_stack *a)
{
	t_stack *b;
	while (a->next)
	{
		b = a->next;
		while (b)
		{
			if (a->n == b->n)
			{
				ft_printf("Error\n");
				return(1);
			}
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (a->next == NULL)
		exit(1);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (0);
		else if (a->n == a->next->n)
		{
			ft_printf("Error\n");
			return(1);
		}
		else
			a = a->next;
	}
	return (1);
}