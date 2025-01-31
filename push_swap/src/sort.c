/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-31 17:51:02 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-31 17:51:02 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size > 5)
		radix_sort(a, b);
}

void	sort_2(t_stack *a)
{
	if (a->array[a->size - 1] < a->array[a->size - 2])
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	third = a->array[a->size - 1];
	second = a->array[a->size - 2];
	first = a->array[a->size - 3];
	if (first > second && second < third && first < third)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && second > third && first > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
		sa(a);
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_max(a, b);
	push_max(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
