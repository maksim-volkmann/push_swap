/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:17:56 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 16:10:54 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Utility functions
bool	is_sorted(t_stack *stack);
int		get_square_root(int x);
int		get_stack_size(t_stack *stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size);

// Clean up
void	free_stack(t_stack **stack);
void	free_words(char ***words);
void	handle_error(t_stack **stack, char **words);

// Swap instructions
void	swap(t_stack **stack);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

// Push instructions
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

// Rotate instructions
void	rotate(t_stack **stack);;
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

// Reverse rotate instructions
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

// Process and initialize stack
bool	has_duplicate(t_stack *stack, int value);
bool	append_node(t_stack **stack, int value);
bool	ft_strtoi(const char *str, int *number);
void	process_and_validate_word(char **words, t_stack **stack);
void	process_args(int ac, char **av, t_stack **stack);

// Get and assign indexes
void	assign_sorted_indexes(t_stack **stack, int *sorted_values, int size);
void	bubble_sort(int *array, int size);
int		*create_values_array(t_stack *stack, int size);
void	get_and_assign_indexes(t_stack **stack);

// Small sort
t_stack	*find_minimum_element(t_stack **stack);
int		get_node_position(t_stack **stack, t_stack *node);
void	rotate_minimum_to_top(t_stack **stack, int size, t_stack *min_node);
void	sort_up_to_5(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);

// Big sort
int		count_rotations_up(t_stack **stack, t_stack *node);
int		count_rotations_down(t_stack **stack, t_stack *node);
t_stack	*find_maximum_element(t_stack **stack);
void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort_by_partitions(t_stack **stack_a, t_stack **stack_b, int s_size);

#endif
