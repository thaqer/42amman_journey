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


// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	j;
// 	int	max;
// 	int	digit;

// 	max = find_max(a);
// 	digit = 1;
// 	while (max / digit > 0)
// 	{
// 		j = 0;
// 		while (j > a->size)
// 		{
// 			if ((a->array[0] / digit) % 10 == 0)
// 				pb(a, b);
// 			else
// 				ra(a);
// 			j--;
// 		}
// 		while (b->size > 0)
// 			pa(a, b);
// 		digit *= 10;
// 	}
// }

int	find_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->array[i];
	while (i < a->size)
	{
		if (a->array[i] > max)
			max = a->array[i];
		i++;
	}
	return (max);
}
