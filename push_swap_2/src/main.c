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
	print_stack(a);
	// if (is_sorted(a))
	// 	exit_program(a, b);
	sort(a, b);
	ft_printf("\n");
	print_stack(a);
	exit_program(a, b);
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
}