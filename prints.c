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
	}
}
