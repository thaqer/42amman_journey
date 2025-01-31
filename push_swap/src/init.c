/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
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
}

void	init_stack_b(t_stack *b, int size)
{
	b->size = 0;
	b->index = -1;
	b->array = malloc(sizeof(int) * size);
}

void	init_arguments(t_stack *a, int argc, char **argv)
{
	int	x;

	x = 0;
	while (x < argc - 1)
	{
		a->array[a->size - 1 - a->index] = ft_atoi(argv[x + 1]);
		a->index--;
		x++;
	}
	a->index = a->size - 1;
}

void	parse_arguments(t_stack *a, char *arg)
{
	char	**numbers;
	int		x;
	int		count;

	numbers = ft_split(arg, ' ');
	count = 0;
	while (numbers[count])
		count++;
	x = 0;
	while (x < count)
	{
		a->array[a->size - 1 - a->index] = ft_atoi(numbers[x]);
		a->index--;
		x++;
	}
	a->index = a->size - 1;
	x = 0;
	while (numbers[x])
		free(numbers[x++]);
	free(numbers);
}

int	count_arguments(char *arg)
{
	int		count;
	int		x;
	char	**numbers;

	count = 0;
	x = 0;
	numbers = ft_split(arg, ' ');
	while (numbers[count])
		count++;
	while (numbers[x])
	{
		free(numbers[x]);
		x++;
	}
	free(numbers);
	return (count);
}
