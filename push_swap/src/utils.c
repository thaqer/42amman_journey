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
	value = stack->array[stack->index];
	stack->index--;
	stack->size--;
	return (value);
}

void	push_stack(t_stack *stack, int value)
{
	stack->index++;
	stack->size++;
	stack->array[stack->index] = value;
}
