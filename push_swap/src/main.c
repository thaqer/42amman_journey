/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:44:37 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/30 00:20:22 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int count_arguments(char *arg)
{
    int count = 0;
    char **numbers = ft_split(arg, ' ');
    while (numbers[count])
        count++;
    for (int i = 0; numbers[i]; i++)
        free(numbers[i]);
    free(numbers);
    return count;
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    if (argc == 2)
    {
        int count = count_arguments(argv[1]);
        init_stack_a(&a, count);
        init_stack_b(&b, count);
        parse_arguments(&a, argv[1]);
    }
    else
    {
        init_stack_a(&a, argc - 1);
        init_stack_b(&b, argc - 1);
        init_arguments(&a, argc, argv);
    }
    printf("Before swap:\n");
    print_stack(&a);
    sa(&a);
    printf("After swap:\n");
    print_stack(&a);   
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

void print_stack(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->index)
    {
        printf("%d\n", a->array[i]);
        i++;
    }
}