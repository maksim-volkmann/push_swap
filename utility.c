/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:32:21 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 14:14:40 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		ra(stack_a, 1);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && stack_size <= 5)
		sort_up_to_5(stack_a, stack_b);
	else
		sort_by_partitions(stack_a, stack_b, stack_size);
}

bool	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	get_square_root(int x)
{
	int	start;
	int	end;
	int	mid;
	int	ans;

	if (x == 0 || x == 1)
		return (x);
	start = 1;
	end = x / 2;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid <= x / mid)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return (ans);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
