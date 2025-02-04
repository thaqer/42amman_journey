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

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				temp_v;
	int				value;
	int				temp;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_stack				*init_stack(void);
void				parse_arguments(t_stack *a, t_stack *b, char *arg);
void				init_arguments(t_stack *a, t_stack *b, int argc,
						char **argv);
void				repetition(t_stack *a, t_stack *b);
void				is_valid(char *arg, t_stack *a, t_stack *b);
void				check_arguments(t_stack *a, t_stack *b);
void				print_stack(t_stack *a);
void				push_stack(t_stack *stack, int value);
void				sort(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);
void				do_radix_sort(t_stack *a, t_stack *b, int max_bits);
void				give_index(t_node *a);
void				switch_values(t_node *a);
void				sort_2(t_stack *a);
void				sort_3(t_stack *a);
void				sort_4(t_stack *a, t_stack *b);
void				sort_5(t_stack *a, t_stack *b);
void				push_min(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rra(t_stack *a);
void				exit_program(t_stack *a, t_stack *b);
void				error_program(t_stack *a, t_stack *b);
void				is_int(t_stack *a, t_stack *b);
int					find_max_bits(t_node *a);
int					is_sorted(t_stack *a);
int					count_arguments(char *arg);
int					pull_stack(t_stack *stack);
int					find_min(t_stack *a);
int					stack_size(t_stack *a);
long				ft_atol(const char *nptr);

#endif