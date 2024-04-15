/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:08:27 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 09:51:13 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	process_args(ac, av, &stack_a);
	if (is_sorted(stack_a) && !stack_b)
	{
		free_stack(&stack_a);
		return (1);
	}
	get_and_assign_indexes(&stack_a);
	stack_size = get_stack_size(stack_a);
	sort_stack(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
