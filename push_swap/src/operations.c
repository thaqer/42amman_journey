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

	if (a->size < 2 || !a->array)
		return ;
	tmp = a->array[a->size - 1];
	a->array[a->size - 1] = a->array[a->size - 2];
	a->array[a->size - 2] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2 || !b->array)
		return ;
	tmp = b->array[b->size - 1];
	b->array[b->size - 1] = b->array[b->size - 2];
	b->array[b->size - 2] = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size == 0 || !a->array)
		return ;
	tmp = pull_stack(a);
	push_stack(b, tmp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->size == 0 || !b->array)
		return ;
	tmp = pull_stack(b);
	push_stack(a, tmp);
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	int	tmp;
	int	x;

	if (a->size < 2 || !a->array)
		return ;
	tmp = a->array[0];
	x = 0;
	while (x < a->size - 1)
	{
		a->array[x] = a->array[x + 1];
		x++;
	}
	a->array[a->size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	int	tmp;
	int	x;

	if (a->size < 2 || !a->array)
		return ;
	tmp = a->array[a->size - 1];
	x = a->size - 1;
	while (x > 0)
	{
		a->array[x] = a->array[x - 1];
		x--;
	}
	a->array[0] = tmp;
	write(1, "rra\n", 4);
}
