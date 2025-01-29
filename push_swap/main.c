/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 19:44:37 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-29 19:44:37 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    init_stack_a(&a, argc);
    init_stack_b(&b, argc);
    if (argc == 2)
        parse_arguments(&a, argv[1]);
    else
        init_arguments(&a, argc, argv);
}

void init_arguments(t_stack *a, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        a->array[a->index] = ft_atoi(argv[i]);
        a->index++;
        i++;
    }
}

void parse_arguments(t_stack *a, char *arg)
{
    char **numbers;
    int i;

    numbers = ft_split(arg, ' ');
    i = 0;
    while (numbers[i])
    {
        a->array[a->index] = ft_atoi(numbers[i]);
        a->index++;
        i++;
    }
    i = 0;
    while (numbers[i])
        free(numbers[i++]);
    free(numbers);
}