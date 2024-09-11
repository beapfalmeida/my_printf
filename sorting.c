/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:33:18 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/09/11 16:42:36 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if ((*a)->n > (*a)->next->n
		&& (*a)->next->n > (*a)->next->next->n)
	{
		swap(a, 1);
		reverse_rotate(a, 1);
	}
	else if ((*a)->n > (*a)->next->n
		&& (*a)->n > (*a)->next->next->n)
	{
		rotate(a, 1);
		if ((*a)->n > (*a)->next->n)
			swap(a, 1);
	}
	else if ((*a)->n > (*a)->next->n
		&& (*a)->n < (*a)->next->next->n)
		swap(a, 1);
	else if ((*a)->n < (*a)->next->n
		&& (*a)->n > (*a)->next->next->n)
		reverse_rotate(a, 1);
	else if ((*a)->n < (*a)->next->n
		&& (*a)->n < (*a)->next->next->n)
	{
		reverse_rotate(a, 1);
		swap(a, 1);
	}
}

void	sort_4(t_stack **a, int i)
{
	t_stack	**ptr_b;
	t_stack	*b;

	b = new_node(0);
	ptr_b = &b;
	if ((*a)->index == i)
		push(a, ptr_b, 0);
	else
	{
		if ((*a)->next->next->next->index == i)
			reverse_rotate(a, 1);
		while (a && (*a) && (*a)->index != i)
			rotate(a, 1);
		push(a, ptr_b, 0);
	}
	sort_3(a);
	push(ptr_b, a, 1);
	if (ptr_b)
		lstclear(ptr_b);
}

void	sort_5(t_stack **a)
{
	t_stack	**ptr_b;
	t_stack	*b;

	b = new_node(0);
	ptr_b = &b;
	if ((*a)->index == 0)
		push(a, ptr_b, 0);
	else
	{
		if ((*a)->next->next->next->next->index == 0)
			reverse_rotate(a, 1);
		else if ((*a)->next->next->next->index == 0)
		{
			reverse_rotate(a, 1);
			reverse_rotate(a, 1);
		}
		while (a && (*a) && (*a)->index != 0)
			rotate(a, 1);
		push(a, ptr_b, 0);
	}
	sort_4(a, 1);
	push(ptr_b, a, 1);
	if (ptr_b)
		lstclear(ptr_b);
}

void	sort_big(t_stack **a)
{
	t_stack	*b;
	int		n;
	int		j;
	int		max_bits;

	b = NULL;
	j = 0;
	n = count_stack(*a);
	max_bits = 0;
	while ((n >> max_bits) != 0)
		max_bits++;
	while (j < max_bits)
	{
		radix(a, b, j, n);
		j++;
	}
	lstclear(&b);
}

void	sort(t_stack **a)
{
	int	size;

	size = count_stack(*a);
	if (size == 2)
	{
		if ((*a)->n > (*a)->next->n)
			swap(a, 1);
	}
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, 0);
	else if (size == 5)
		sort_5(a);
	else if (size > 5)
		sort_big(a);
	lstclear(a);
}
