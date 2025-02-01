/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 19:13:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-30 19:13:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void radix_sort(t_stack *a, t_stack *b)
{
	int max_bits;

	give_index(a->top);
	switch_values(a->top);
	max_bits = find_max_bits(a->top);
	do_radix_sort(a, b, max_bits);

}

int	find_max_bits(t_node *a)
{
	int max;
	int bits;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while (max)
	{
		max /= 10;
		bits++;
	}
	return (bits);
}

void	give_index(t_node *a)
{
	t_node	*temp;
	int		index;

	temp = a;
	while (temp)
	{
		index = 0;
		while (a)
		{
			if (temp->value > a->value)
				index++;
			a = a->next;
		}
		temp->index = index;
		temp = temp->next;
		a = temp;
	}
	
}

void	switch_values(t_node *a)
{
	while (a)
	{
		a->value = a->index;
		a = a->next;
	}
}

void	do_radix_sort(t_stack *a, t_stack *b, int max_bits)
{
	t_node	*top;
	int	x;
	int	y;

	x = 0;
	while (x < max_bits)
	{
		y = 0;
		while (y < a->size)
		{
			top = a->top;
			if (((top->value >> x) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			y++;
		}
		while (b->top)
			pa(a, b);
		if (is_sorted(a))
			break ;
		x++;
	}
}

