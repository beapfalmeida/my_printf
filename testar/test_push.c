#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
	int	n;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

void	add_front_list(t_stack **a, t_stack *new)
{
	if (a)
	{
		if (*a)
			new->next = *a;
		*a = new;
	}
}

void	push(t_stack **src, t_stack **dest, int is_a)
{
	t_stack *start;

	start = *src;
	*src = (*src)->next;
	// se a lista src so tivesse 1 elmento
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
	{
		start->next = *dest;
		start->next->prev = start;
	}
	else
		start->next = NULL;
	*dest = start;
	if (is_a == 1)
		printf("pa\n");
	else
		printf("pb\n");
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
void create_a(t_stack **a)
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
	*a = aa;
}

void create_b(t_stack **b)
{
	int n1 = 5;
	t_stack *aa = malloc(sizeof(t_stack));
	aa->next = 0;
	aa->prev = 0;
	aa->n = n1;
	int n2 = 6;
	t_stack *bb = malloc(sizeof(t_stack));
	bb->next = 0;
	bb->prev = 0;
	bb->n = n2;
	int n3 = 7;
	t_stack *cc = malloc(sizeof(t_stack));
	cc->next = 0;
	cc->prev = 0;
	cc->n = n3;
	int n4 = 8;
	t_stack *dd = malloc(sizeof(t_stack));
	dd->next = 0;
	dd->n = n4;
	aa->next = bb;
	bb->next = cc;
	bb->prev = aa;
	cc->next = dd;
	cc->prev = bb;
	dd->prev = cc;
	*b = aa;
}
int		main(void)
{
	t_stack *begin_list;
	t_stack	*b;
	create_a(&begin_list);
	create_b(&b);
	print_list(&begin_list);
	printf("----------\n");
	push(&begin_list, &b, 0);
	print_list(&b);
}