/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:47:23 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 14:22:50 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_minimum_element(t_stack **stack)
{
	t_stack	*current;
	t_stack	*min_node;

	current = *stack;
	min_node = *stack;
	while (current)
	{
		if (current->index < min_node->index)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

int	get_node_position(t_stack **stack, t_stack *node)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = *stack;
	while (current && current != node)
	{
		current = current->next;
		position++;
	}
	return (position);
}

void	rotate_minimum_to_top(t_stack **stack, int size, t_stack *min_node)
{
	int	pos;

	pos = get_node_position(stack, min_node);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(stack, 1);
	}
	else
	{
		while ((size - pos++) > 0)
			rra(stack, 1);
	}
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(stack, 1);
	else if (first > second && second > third)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else
		rra(stack, 1);
}

void	sort_up_to_5(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		rotate_minimum_to_top(stack_a, size, find_minimum_element(stack_a));
		pb(stack_a, stack_b, 1);
		size--;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, 1);
}
