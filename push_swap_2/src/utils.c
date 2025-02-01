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
	t_node *new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_program(stack, NULL);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pull_stack(t_stack *stack)
{
	int	tmp;
	t_node *temp;

	if (stack->size == 0)
		error_program(stack, NULL);
	tmp = stack->top->value;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (tmp);
}

int	is_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_max(t_stack *a)
{
	int max;
	t_node *current;

	current = a->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int find_min(t_stack *a)
{
	int min;
	t_node *current;

	current = a->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}


void push_min(t_stack *a, t_stack *b)
{
	int min;

	min = find_min(a);
	while (a->top->value != min)
		ra(a);
	pb(a, b);
}
void	push_max(t_stack *a, t_stack *b)
{
	int	max;

	max = find_max(a);
	while (a->top->value != max)
		ra(a);
	pb(a, b);
}
