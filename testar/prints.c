#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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

void	print_bits(unsigned int octet)
{
	int i;
	char bit[32];
	i = 31;
	bit[i] = '\0';
	while (i > 0)
	{
		i--;
		if ((octet % 2) == 0)
			bit[i] = '0';
		else
			bit[i] = '1';
		octet = octet >> 1;
	}
	write(1, bit, 31);
}
