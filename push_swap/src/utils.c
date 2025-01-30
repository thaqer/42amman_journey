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

int	pull_stack(t_stack *stack)
{
	int	value;

	if (stack->size == 0)
		return (INT_MIN);
	value = stack->array[0];
	for (int i = 0; i < stack->size - 1; i++)
	{
		stack->array[i] = stack->array[i + 1];
	}
	stack->size--;
	stack->index--;
	return (value);
}

void	push_stack(t_stack *stack, int value)
{
	stack->index++;
	stack->array[stack->index] = value;
	stack->size++;
}
