/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 19:25:07 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-01-29 19:25:07 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int		value;
    int		index;
    struct s_node	*next;
}		t_node;

typedef struct s_stack
{
    int		*array;
    int		index;
    int		size;
}		t_stack;

void	init_stack_a(t_stack *stack, int size);
void	init_stack_b(t_stack *stack, int size);
void	parse_arguments(t_stack *a, char *arg);
void	init_arguments(t_stack *a, int argc, char **argv);
void	sa(t_stack *a);

#endif