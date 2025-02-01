/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 10:10:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-02-01 10:10:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node *temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}

void	exit_program(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

void	error_program(t_stack *a, t_stack *b)
{
	ft_printf("Error\n");
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}