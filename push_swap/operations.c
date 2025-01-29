/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 19:31:48 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-29 19:31:48 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2 || a.array == NULL)
		return ;
	tmp = a->array[a->index];
	a->array[a->index] = a->array[a->index + 1];
	a->array[a->index + 1] = tmp;
}