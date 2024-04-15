/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_assign_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:14:42 by mvolkman          #+#    #+#             */
/*   Updated: 2024/04/12 10:23:44 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_sorted_indexes(t_stack **stack, int *sorted_values, int size)
{
	t_stack	*current;
	int		i;

	current = *stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_values[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	bubble_sort(int *array, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*create_values_array(t_stack *stack, int size)
{
	int	*values;
	int	i;

	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	i = 0;
	while (i < size)
	{
		values[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (values);
}

void	get_and_assign_indexes(t_stack **stack)
{
	int	size;
	int	*values;

	size = get_stack_size(*stack);
	values = create_values_array(*stack, size);
	if (!values)
		return ;
	bubble_sort(values, size);
	assign_sorted_indexes(stack, values, size);
	free(values);
}
