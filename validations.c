/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:33:16 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/09/11 18:27:49 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *a)
{
	t_stack	*b;

	while (a->next)
	{
		b = a->next;
		while (b)
		{
			if (a->n == b->n)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (a->next == NULL)
		return (1);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (0);
		else
			a = a->next;
	}
	return (1);
}

int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i + 1] && str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	return (1);
}

int	bigger_max_min(long n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (1);
	return (0);
}
