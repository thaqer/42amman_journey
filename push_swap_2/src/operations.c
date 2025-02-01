/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:31:48 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/30 00:17:02 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size == 0)
		return ;
	tmp = pull_stack(a);
	push_stack(b, tmp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->size == 0)
		return ;
	tmp = pull_stack(b);
	push_stack(a, tmp);
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	int	tmp;
	t_node *temp;
	t_node *new_node;

	if (a->size < 2)
		return ;
	tmp = pull_stack(a);
	temp = a->top;
	while (temp->next)
		temp = temp->next;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_program(a, NULL);
	new_node->value = tmp;
	new_node->next = NULL;
	temp->next = new_node;
	a->size++;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	int	tmp;
	t_node *temp;
	t_node *prev;

	if (a->size < 2)
		return ;
	temp = a->top;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	tmp = temp->value;
	free(temp);
	prev->next = NULL;
	push_stack(a, tmp);
	write(1, "rra\n", 4);
}
