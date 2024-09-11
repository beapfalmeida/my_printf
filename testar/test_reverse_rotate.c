#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
	int	n;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

t_stack	*find_last(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	reverse_rotate(t_stack **stack, int is_a)
{
	t_stack	*last;

	last = find_last(*stack);
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	printf("stack: %d\n", (*stack)->n);
	printf("stack: %d\n", (*stack)->next->n);
	printf("stack: %d\n", (*stack)->next->next->n);
	printf("stack: %d\n", (*stack)->next->next->next->n);
	(void)is_a;
}

int main()
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
	reverse_rotate(begin_list, 1);
}