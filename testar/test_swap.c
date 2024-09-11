#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
	int	n;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

void swap(t_stack **stack, int is_a)
{
	t_stack	*first;

	first = *stack;
	*stack = (*stack)->next;
	// printf("stack: %d\n", (int)((*stack)->n));
	first->prev = first->next;
	// printf("first->prev: %d\n", (int)(first->prev->n));
	first->next = first->next->next;
	// printf("first->next: %d\n", (int)(first->next->n));
	// printf("stack: %d\n", (int)((*stack)->n));
	(*stack)->prev = NULL;
	(*stack)->next = first;
	// printf("stack->next: %d\n", (int)((*stack)->next->n));
	first->next->prev = first;
	// printf("first->next->prev: %d\n", (int)(first->next->prev->n));
	if (is_a == 1)
		printf("sa\n");
	else
		printf("sb\n");
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
int		main(void)
{
	int n1 = 1;
	t_stack *aa = malloc(sizeof(t_stack));
	aa->next = 0;
	aa->prev = 0;
	aa->n = n1;
	int n2 = 2;
	t_stack *bb = malloc(sizeof(t_stack));
	bb->next = 0;
	bb->prev = 0;
	bb->n = n2;
	int n3 = 3;
	t_stack *cc = malloc(sizeof(t_stack));
	cc->next = 0;
	cc->prev = 0;
	cc->n = n3;
	int n4 = 4;
	t_stack *dd = malloc(sizeof(t_stack));
	dd->next = 0;
	dd->n = n4;
	aa->next = bb;
	bb->next = cc;
	bb->prev = aa;
	cc->next = dd;
	cc->prev = bb;
	dd->prev = cc;
	t_stack **begin_list = &aa;
	print_list(begin_list);
	printf("----------\n");
	swap(begin_list, 1);
	print_list(begin_list);
}