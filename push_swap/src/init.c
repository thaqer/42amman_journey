/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 18:55:22 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-30 18:55:22 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_a(t_stack *a, int size)
{
	a->size = size;
	a->index = size - 1;
	a->array = malloc(sizeof(int) * a->size);
	printf("Initialized stack a with size %d\n", a->size);
}

void	init_stack_b(t_stack *b, int size)
{
	b->size = size;
	b->index = size - 1;
	b->array = malloc(sizeof(int) * b->size);
	printf("Initialized stack b with size %d\n", b->size);
}

void	init_arguments(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		a->array[a->index] = ft_atoi(argv[i]);
		a->index--;
		i++;
	}
}

void	parse_arguments(t_stack *a, char *arg)
{
	char	**numbers;
	int		i;

	numbers = ft_split(arg, ' ');
	i = 0;
	while (numbers[i])
	{
		a->array[a->index] = ft_atoi(numbers[i]);
		a->index--;
		i++;
	}
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

int	count_arguments(char *arg)
{
	int		count;
	int		i;
	char	**numbers;

	count = 0;
	i = 0;
	numbers = ft_split(arg, ' ');
	while (numbers[count])
		count++;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (count);
}
