/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/30 00:18:04 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void   init_stack_a(t_stack *a, int size)
{
    a->size = size;
    a->index = 0;
    a->array = malloc(sizeof(int) * a->size);
    printf("Initialized stack a with size %d\n", a->size); // Debug print
}

void   init_stack_b(t_stack *b, int size)
{
    b->size = size;
    b->index = 0;
    b->array = malloc(sizeof(int) * b->size);
    printf("Initialized stack b with size %d\n", b->size); // Debug print
}