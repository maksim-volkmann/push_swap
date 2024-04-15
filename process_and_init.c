/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:21:58 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 09:59:50 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (false);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (true);
}

bool	has_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	ft_strtoi(const char *str, int *number)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || ((sign == -1) && (-num < INT_MIN)))
			return (false);
		str++;
	}
	*number = sign * num;
	return (true);
}

void	process_and_validate_word(char **words, t_stack **stack)
{
	int	num;
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		if (!ft_strtoi(words[i], &num))
			handle_error(stack, words);
		if (has_duplicate(*stack, num))
			handle_error(stack, words);
		if (!append_node(stack, num))
			handle_error(stack, words);
		i++;
	}
}

void	process_args(int ac, char **av, t_stack **stack)
{
	char	**words;
	int		i;

	i = 1;
	words = NULL;
	while (i < ac)
	{
		words = ft_split(av[i], ' ');
		if (!words)
		{
			free_words(&words);
			write(2, "Error\n", 6);
			exit(1);
		}
		process_and_validate_word(words, stack);
		free_words(&words);
		i++;
	}
}
