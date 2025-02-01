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
	// ft_printf("\n");
	// print_stack(a);
	max_bits = find_max_bits(a->top);
	do_radix_sort(a, b, max_bits);

}

int	find_max_bits(t_node *a)
{
	int	max;
	t_node	*current;

	current = a;
	max = 0;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	give_index(t_node *a)
{
	t_node	*temp;
	t_node	*temp2;
	int		index;

	temp = a;
	temp2 = a;
	while (temp2)
	{
		index = 0;
		temp = a;
		while (temp)
		{
			if (temp->value < temp2->value)
				index++;
			temp = temp->next;
		}
		temp2->index = index;
		temp2 = temp2->next;

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

