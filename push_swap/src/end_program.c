/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 10:10:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-02-01 10:10:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_program(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
	exit(0);
}

void	error_program(t_stack *a, t_stack *b)
{
	ft_printf("Error\n");
	free(a->array);
	free(b->array);
	exit(1);
}