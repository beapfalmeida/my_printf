#include "push_swap.h"

void	insert_index(t_stack **stack, t_stack **new)
{
	t_stack *temp;
	t_stack	*temp_new;
	int	i;
	int size;

	i = 0;
	temp_new = *new;
	size = count_stack(*stack);
	temp = *stack;
	while (i < size)
	{
		temp = *stack;
		while (temp && temp->n != (*new)->n)
			temp = temp->next;
		if (temp)
		{
			temp->index = i;
			*new = (*new)->next;
		}
		i++;
	}
	lstclear(&temp_new);
}
void	put_index(t_stack **stack)
{
	int	buffer;
	t_stack *temp1;
	t_stack	*temp;
	t_stack *new;

	new = copy_struct(*stack);
	temp = new;
	temp1 = new->next;
	while (temp && temp->next)
	{
		while (temp1)
		{
			if (temp->n > temp1->n)
			{
				buffer = temp->n;
				temp->n = temp1->n;
				temp1->n = buffer;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
		temp1 = temp->next;
	}
	insert_index(stack, &new);
	//print_index(stack);
}

int	handle_args(t_stack **stack, int i, char **list, int is_av)
{
	t_stack	*item;
	long	content;
	if (!is_num(list[i]))
		return(goodbye(stack, list, is_av));
	content = ft_atol(list[i]);
	if (!bigger_max_min(content))
	{
		item = new_node(content);
		if (!stack)
			*stack = item;
		else
			add_back_list(stack, item);
		i++;
	}
	else
		return(goodbye(stack, list, is_av));
	return (0);
}
// nota - o stack esta a ficar preso neste scope,
// ver se depois nao preciso dele para mais nada
int parse_handle_args(t_stack *stack, char **av)
{
	char	**list;
	int		i;

	i = 0;
	list = ft_split(av[1], ' ');
	if (list == NULL)
		return (1);
	while (list[i] != NULL)
	{
		if (handle_args(&stack, i, list, 0) == 1)
			return (1);
		i++;
	}
	free_arr(list);
	if (!is_sorted(stack) && !has_duplicates(stack))
	{
		zero_index(&stack);
		put_index(&stack);
		sort(&stack);
	}
	else
		lstclear(&stack);
	return (0);
}

int main(int ac, char **av)
{
	int	i;
	int big;
	t_stack *stack = NULL;

	i = 1;
	big = 0;
	if (ac == 1)
		return (1);
	else if (ac == 2)
		return (parse_handle_args(stack, av));
	else
	{
		while (i < ac)
		{
			if (handle_args(&stack, i, av, 1) == 1)
				return (1);
			i++;
		}
		//big = bigger_max_min(stack);
		if (!is_sorted(stack) && !has_duplicates(stack))
		{
			put_index(&stack);
			sort(&stack);
		}
		else
			lstclear(&stack);
	}
	return (0);
}

