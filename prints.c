#include "push_swap.h"

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

void	print_index(t_stack **begin_list)
{
	t_stack *cur = *begin_list;
	while (cur != 0)
	{
		printf("stack[%d]", (int)(cur->index));
		printf(" = %d\n", (int)(cur->n));
		cur = cur->next;
		printf("hey");
	}
}

void	tentativa1(t_stack **stack, int index)
{
	int j;
	t_stack *k;
	t_stack	*temp;

	k = *stack;
	temp = (*stack)->next;
	while (k && k->next && k->next->next)
	{
		j = 0;
		while (temp)
		{
			if (k->n > temp->n)
			{
				k = k->next;
				j = 1;
			}
			temp = temp->next;
		}
		if (j == 0)
			break ;
		temp = k->next;
	}
	k->index = index;
	index++;
	while (index < (count_stack(*stack)))
		put_index(stack, index);
}