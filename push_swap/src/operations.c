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

	if (a->size < 2 || a->array == NULL)
		return ;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
}