/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 11:55:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-02-02 11:55:26 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	repetition(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*temp2;

	temp = a->top;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				error_program(a, b);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	is_int(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (temp->value > INT_MAX || temp->value < INT_MIN)
			error_program(a, b);
		temp = temp->next;
	}
}

void	check_arguments(t_stack *a, t_stack *b)
{
	repetition(a, b);
	is_int(a, b);
}
