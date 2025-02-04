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
	t_node	*temp;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = a->top->next;
	a->top->next = temp;
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size == 0 || !a)
		return ;
	tmp = pull_stack(a);
	push_stack(b, tmp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->size == 0 || !b)
		return ;
	tmp = pull_stack(b);
	push_stack(a, tmp);
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*last;

	if (a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*temp;
	t_node	*temp2;

	if (a->size < 2)
		return ;
	temp = a->top;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = a->top;
	a->top = temp2;
	write(1, "rra\n", 4);
}

// void	sb(t_stack *b)
// {
// 	int	tmp;

// 	if (b->size < 2)
// 		return ;
// 	tmp = b->top->value;
// 	b->top->value = b->top->next->value;
// 	b->top->next->value = tmp;
// 	write(1, "sb\n", 3);
// }

// void	ss(t_stack *a, t_stack *b)
// {
// 	t_node	*temp;
// 	t_node	*temp2;

// 	temp = a->top;
// 	temp2 = b->top;
// 	a->top = temp->next;
// 	temp->next = a->top->next;
// 	a->top->next = temp;
// 	b->top = temp2->next;
// 	temp2->next = b->top->next;
// 	b->top->next = temp2;
// 	write(1, "ss\n", 3);

// }

// void	rr(t_stack *a, t_stack *b)
// {
// 	t_node	*temp;
// 	t_node	*temp2;
// 	t_node	*last;

// 	temp = a->top;
// 	temp2 = b->top;
// 	a->top = temp->next;
// 	temp->next = NULL;
// 	last = a->top;
// 	while (last->next)
// 		last = last->next;
// 	last->next = temp;
// 	b->top = temp2->next;
// 	temp2->next = b->top->next;
// 	b->top->next = temp2;
// 	write(1, "rr\n", 3);
// }