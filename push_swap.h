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

int	handle_args(t_stack **stack, int i, char **list);
int parse_handle_args(t_stack *stack, char **av);

//list utils
void	add_back_list(t_stack **lst, t_stack *new);
t_stack	*find_last(t_stack *lst);
t_stack	*new_node(int num);
void	lstclear(t_stack **lst);

//sort
int	is_sorted(t_stack *a);
int	count_stack(t_stack *a);
void	sort(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a);
void	sort_5(t_stack **a);
void	sort_big(t_stack **a);

//operations 1
void	swap(t_stack ***stack, int is_a);
void	ss(t_stack ****a, t_stack ****b);
void	push(t_stack ***src, t_stack ***dest, int is_a);
void	rotate(t_stack ***stack, int is_a);
void	rr(t_stack	****a, t_stack ****b);

//operations 2
void	reverse_rotate(t_stack ***stack, int is_a);
void	rrr(t_stack ****a,  t_stack ****b);

#endif