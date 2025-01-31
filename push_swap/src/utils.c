/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/30 00:18:04 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	stack->size++;
	stack->array[stack->size - 1] = value;
}

int	pull_stack(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->size - 1];
	stack->size--;
	return (tmp);
}

int	is_sorted(t_stack *a)
{
	int	x;

	x = 0;
	while (x < a->size - 1)
	{
		if (a->array[x] > a->array[x + 1])
			return (0);
		x++;
	}
	return (1);
}

int	find_max(t_stack *a)
{
	int	x;
	int	max;

	x = 0;
	max = a->array[x];
	while (x < a->size)
	{
		if (a->array[x] > max)
			max = a->array[x];
		x++;
	}
	return (max);
}

int	find_min(t_stack *a)
{
	int	x;
	int	min;

	x = 0;
	min = a->array[x];
	while (x < a->size)
	{
		if (a->array[x] < min)
			min = a->array[x];
		x++;
	}
	return (min);
}

void	push_min(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	min = find_min(a);
	i = 0;
	while (i < a->size)
	{
		if (a->array[a->size - 1] == min)
		{
			pb(a, b);
			break ;
		}
		ra(a);
		i++;
	}
}

void	push_max(t_stack *a, t_stack *b)
{
	int	max;
	int	i;

	max = find_max(a);
	i = 0;
	while (i < a->size)
	{
		if (a->array[a->size - 1] == max)
		{
			pb(a, b);
			break ;
		}
		ra(a);
		i++;
	}
}