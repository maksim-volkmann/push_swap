/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldman <goldman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:20:04 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/11 20:37:03 by goldman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_words(char ***words)
{
	int	i;

	if (words != NULL && *words != NULL)
	{
		i = 0;
		while ((*words)[i])
		{
			free((*words)[i]);
			i++;
		}
		free(*words);
		*words = NULL;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;

	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
}

void	handle_error(t_stack **stack, char **words)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	free_words(&words);
	exit(1);
}
