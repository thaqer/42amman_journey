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

void	init_arguments(t_stack *a, int argc, char **argv)
{
	int		x;
	t_node	*new_node;

	x = 1;
	if (argc == 2)
	{
		a->size = count_arguments(argv[1]);
		parse_arguments(a, argv[1]);
	}
	else
	{
		a->size = argc - 1;
		x = a->size;
		while (x > 0)
		{
			new_node = malloc(sizeof(t_node));
			if (!new_node)
				error_program(a, NULL);
			new_node->value = ft_atoi(argv[x]);
			new_node->next = a->top;
			a->top = new_node;
			x--;
		}
	}
}

void	parse_arguments(t_stack *a, char *arg)
{
	char	**numbers;
	int		x;
	t_node	*new_node;

	numbers = ft_split(arg, ' ');
	x = a->size - 1;
	while (x >= 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			error_program(a, NULL);
		new_node->value = ft_atoi(numbers[x]);
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
