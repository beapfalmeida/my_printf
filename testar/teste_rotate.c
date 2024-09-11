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

void	add_back_list(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = find_last(*lst);
	last -> next = new;
}

void	rotate(t_stack **a, int is_a)
{
	t_stack	*last;

	last = find_last(*a);
	(*a)->prev = last;
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
	(*a)->prev = NULL;
	if (is_a == 1)
		printf("ra\n");
	else
		printf("rb\n");
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
	rotate(begin_list, 1);
	print_list(begin_list);
}