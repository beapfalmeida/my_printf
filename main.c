#include "push_swap.h"

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
int	handle_args(char **av, int i, char **list)
{
	t_stack	*a;
	t_stack	*item;

	if (!ft_atoi(list[i]))
	{
		free_arr(list);
		return (invalid_args(av[0]));
	}
	item = new_node(ft_atoi(list[i]));
	add_back_list(&a, item);
	i++;
	return (0);
}

int multiple_args(char **av)
{
	char	**list;
	int		i;

	i = 0;
	list = ft_split(av[1], ' ');
	if (list == NULL)
		return (invalid_args(av[0]));
	while (list[i] != NULL)
	{
		if (handle_args(av, i, list) == 1)
			return (1);
	}
	free_arr(list);
	return (0);
}

int	invalid_args(char *str)
{
	ft_printf("Please provide a list of numbers:\n");
	ft_printf("%s ""51 ... 28 3""", str);
	ft_printf("%s 51 ... 28 3", str);
	return (1);
}

int main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		return (invalid_args(av[0]));
	else if (ac == 2)
		return (multiple_args(av));
	else
	{
		while (i < ac - 1)
		{
			if (handle_args(av, i, av) == 1)
				return (1);
		}
	}
	return (0);
}

