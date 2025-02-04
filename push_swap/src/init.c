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

t_stack	*init_stack(void)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		error_program(a, NULL);
	a->top = NULL;
	a->size = 0;
	return (a);
}

void	init_arguments(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		x;
	t_node	*new_node;
	long	value;

	if (argc == 2)
		parse_arguments(a, b, argv[1]);
	else
	{
		a->size = argc - 1;
		x = a->size;
		while (x > 0)
		{
			is_valid(argv[x], a, b);
			value = ft_atol(argv[x]);
			if (value > INT_MAX || value < INT_MIN)
				error_program(a, b);
			new_node = malloc(sizeof(t_node));
			if (!new_node)
				error_program(a, b);
			new_node->value = (int)value;
			new_node->next = a->top;
			a->top = new_node;
			x--;
		}
	}
}

void	is_valid(char *arg, t_stack *a, t_stack *b)
{
	int	x;

	x = 0;
	if (arg[x] == '-' || arg[x] == '+')
		x++;
	while (arg[x])
	{
		if (!ft_isdigit(arg[x]))
			error_program(a, b);
		x++;
	}
}

void	parse_arguments(t_stack *a, t_stack *b, char *arg)
{
	char	**numbers;
	int		x;
	t_node	*new_node;

	a->size = count_arguments(arg);
	numbers = ft_split(arg, ' ');
	x = a->size - 1;
	while (x >= 0)
	{
		is_valid(numbers[x], a, b);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			error_program(a, b);
		new_node->value = ft_atol(numbers[x]);
		new_node->next = a->top;
		a->top = new_node;
		x--;
	}
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
