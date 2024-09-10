#include "push_swap.h"

long	ft_atol(const char *str)
{
	int	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
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

t_stack	*copy_struct(t_stack *stack)
{
	t_stack *temp;
	t_stack	*new;
	t_stack	*item;

	new = NULL;
	temp = stack;
	while (temp)
	{
		item = new_node(temp->n);
		if (!new)
			new = item;
		else
			add_back_list(&new, item);
		temp = temp->next;
	}
	return (new);
}

int goodbye(t_stack **stack, char **list, int is_av)
{
	if (!is_av)
			free_arr(list);
		if (stack)
			lstclear(stack);
		ft_printf("Error\n");
		return (1);
}
