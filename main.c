#include "push_swap.h"

void	insert_index(t_stack **stack)
{
	t_stack *temp;
	int	i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	put_index(t_stack **stack)
{
	int	buffer;
	t_stack *temp1 = NULL;
	t_stack	*temp2 = NULL;

	temp2 = *stack;
	temp1 = (*stack)->next;
	while (temp2 && temp2->next)
	{
		while (temp1)
		{
			if (temp2->n > temp1->n)
			{
				buffer = temp2->n;
				temp2->n = temp1->n;
				temp1->n = buffer;
			}
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
		temp1 = temp2->next;
	}
	insert_index(stack);
	//print_index(stack);
}

void	free_arr(char **arr)
{
	int	j;

	j = 0;
	while (arr[j] != NULL)
	{
		free(arr[j++]);
	}
	free(arr);
}
int	handle_args(t_stack **stack, int i, char **list)
{
	t_stack	*item;
	if (!ft_atoi(list[i]))
	{
		free_arr(list);
		ft_printf("Error\n");
		return (1);
	}
	item = new_node(ft_atoi(list[i]));
	if (!stack)
		*stack = item;
	else
		add_back_list(stack, item);
	i++;
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
		if (handle_args(&stack, i, list) == 1)
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
	t_stack *stack = NULL;

	i = 1;
	if (ac == 1)
		return (1);
	else if (ac == 2)
		return (parse_handle_args(stack, av));
	else
	{
		while (i < ac)
		{
			if (handle_args(&stack, i, av) == 1)
				return (1);
			i++;
		}
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

