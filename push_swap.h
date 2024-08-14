#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct stack
{
	int	n;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

int	argument_handler(char **av, int ac);
int	multiple_args(char **av, int ac);
int	invalid_args(char *str);

//handle lists
void	add_back_list(t_stack **lst, t_stack *new);
t_stack	*find_last(t_stack *lst);
t_stack	*new_node(int num);

#endif