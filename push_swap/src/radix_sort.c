/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 19:13:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-30 19:13:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;
	int		num;

	max_bits = 0;
	while ((a->size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->size)
		{
			num = a->array[a->size - 1];
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size != 0)
			pa(a, b);
		i++;
	}
}

void	counting_sort(t_stack *a, int exp)
{
	int		count[10];
	int		x;
	int		output[a->size];

	x = 0;
	while (x < 10)
		count[x++] = 0;
	x = 0;
	while (x < a->size)
		count[(a->array[x] / exp) % 10]++;
	x = 1;
	while (x < 10)
	{
		count[x] += count[x - 1];
		x++;
	}
	x = a->size - 1;
	while (x >= 0)
	{
		output[count[(a->array[x] / exp) % 10] - 1] = a->array[x];
		count[(a->array[x] / exp) % 10]--;
		x--;
	}
	x = 0;
	while (x < a->size)
	{
		a->array[x] = output[x];
		x++;
	}
}
