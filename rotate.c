/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:57:46 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 08:57:49 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = first->next;
		first->next = NULL;
		tmp->next = first;
	}
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
