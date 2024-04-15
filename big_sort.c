/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:17:27 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 19:14:03 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotations_up(t_stack **stack, t_stack *max_node)
{
	int		moves;
	t_stack	*current;

	moves = 0;
	current = *stack;
	while (current != max_node)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

int	count_rotations_down(t_stack **stack, t_stack *max_node)
{
	int		moves;
	t_stack	*current;

	moves = 0;
	current = *stack;
	while (current != max_node)
		current = current->next;
	while (current)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

t_stack	*find_maximum_element(t_stack **stack)
{
	t_stack	*current;
	t_stack	*max_node;

	current = *stack;
	max_node = *stack;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_node;
	int		moves_up;
	int		moves_down;

	while (get_stack_size(*stack_b) != 0)
	{
		max_node = find_maximum_element(stack_b);
		moves_down = count_rotations_down(stack_b, max_node);
		moves_up = count_rotations_up(stack_b, max_node);
		if (moves_down < moves_up)
		{
			while (moves_down--)
				rrb(stack_b, 1);
		}
		else
		{
			while (moves_up--)
				rb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	sort_by_partitions(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	t_stack	*current;
	int		index;
	int		range;

	current = (*stack_a);
	index = 0;
	range = ((int)get_square_root(s_size) * 14) / 10;
	while (current != NULL)
	{
		if (current->index <= index)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			index++;
		}
		else if (current->index <= index + range)
		{
			pb(stack_a, stack_b, 1);
			index++;
		}
		else
			ra(stack_a, 1);
		current = (*stack_a);
	}
	sort_back_to_a(stack_a, stack_b);
}
