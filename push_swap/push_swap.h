/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:25:07 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/30 00:09:07 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../push_swap/printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				*array;
	int				index;
	int				size;
}					t_stack;

void				init_stack_a(t_stack *stack, int size);
void				init_stack_b(t_stack *stack, int size);
void				parse_arguments(t_stack *a, char *arg);
void				init_arguments(t_stack *a, int argc, char **argv);
void				print_stack(t_stack *a);
void				push_stack(t_stack *stack, int value);
void				radix_sort(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rra(t_stack *a);
int					count_arguments(char *arg);
int					pull_stack(t_stack *stack);
int					find_max(t_stack *a);


#endif