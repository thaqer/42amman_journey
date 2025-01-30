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
	tmp = a->array[a->index];
	a->array[a->index] = a->array[a->index - 1];
	a->array[a->index - 1] = tmp;
	write(1, "sa\n", 3);
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
	int	i;

	if (a->size < 2 || !a->array)
		return ;
	tmp = a->array[a->index];
	i = a->index;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2 || !a->array)
		return ;
	tmp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = tmp;
	write(1, "rra\n", 4);
}
