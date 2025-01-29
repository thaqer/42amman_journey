/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 19:46:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-29 19:46:13 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   init_stack_a(t_stack *a, int argc)
{
    a->size = argc - 1;
    a->index = 0;
    a->array = malloc(sizeof(int) * a->size);
}

void   init_stack_b(t_stack *b, int argc)
{
    b->size = argc - 1;
    b->index = 0;
    b->array = malloc(sizeof(int) * b->size);
}