/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:33:30 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/09/11 15:34:10 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack, int is_a)
{
	t_stack	*last;

	last = find_last(*stack);
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	if (is_a == 1)
		ft_printf("rra\n");
	else if (is_a == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
	ft_printf("rrr");
}

void	check_and_sort(t_stack **stack)
{
	if (!is_sorted(*stack) && !has_duplicates(*stack))
	{
		zero_index(stack);
		put_index(stack);
		sort(stack);
	}
	else
		lstclear(stack);
}

void	radix(t_stack **a, t_stack *b, int j, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((((*a)->index) >> j) & 1) == 1)
			rotate(a, 1);
		else
			push(a, &b, 0);
		i++;
	}
	if (b)
		push(&b, a, 1);
	while (b)
		push(&b, a, 1);
}
