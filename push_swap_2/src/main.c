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
	t_stack	*a;
	t_stack	*b;

	(void)argv;
	if (argc < 2)
		return (0);
	a = init_stack();
	if (!a)
		error_program(a, NULL);
	b = init_stack();
	if (!b)
		error_program(a, b);
	init_arguments(a, argc, argv);
	check_arguments(a);
	sort(a, b);
	exit_program(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;

	give_index(a->top);
	switch_values(a->top);
	a->top->temp = stack_size(a);
	max_bits = find_max_bits(a->top);
	do_radix_sort(a, b, max_bits);
}

void	print_stack(t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = a->top;
}
