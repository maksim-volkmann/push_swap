/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:42:54 by goldman           #+#    #+#             */
/*   Updated: 2024/04/12 20:22:33 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	validate_and_output(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	execute_instruction(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instr, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(instr, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(instr, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(instr, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(instr, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(instr, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(instr, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(instr, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(instr, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(instr, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(instr, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

void	read_and_execute_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;
	int		stdinput;

	stdinput = 0;
	instruction = get_next_line(stdinput);
	while (instruction != NULL)
	{
		if (!execute_instruction(instruction, stack_a, stack_b))
		{
			free(instruction);
			write(2, "Error\n", 6);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		free(instruction);
		instruction = get_next_line(stdinput);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	process_args(ac, av, &stack_a);
	read_and_execute_instructions(&stack_a, &stack_b);
	validate_and_output(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
