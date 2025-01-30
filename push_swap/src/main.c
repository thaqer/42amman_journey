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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		count = count_arguments(argv[1]);
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
	printf("Before:\n");
	print_stack(&a);
	radix_sort(&a, &b);
	printf("After:\n");
	print_stack(&a);
}

void	print_stack(t_stack *a)
{
	int	i;

	i = a->size - 1;
	while (i > a->index)
	{
		printf("%d\n", a->array[i]);
		i--;
	}
}
