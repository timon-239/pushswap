/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   index.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 14:50:44 by tireis           #+#    #+#              */
/*   Updated: 2026/06/01 12:44:53 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *a)
{
	int		size;
	int		i;
	int		*arr;
	t_stack	*current;

	if (!a)
		return (0);
	i = 0;
	current = a;
	size = ft_stacksize(a);
	if (size <= 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	temp;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index(t_stack *a)
{
	int		*arr;
	int		size;
	t_stack	*tmp;

	tmp = a;
	size = ft_stacksize(a);
	arr = stack_to_array(a);
	sort_array(arr, size);
	while (tmp)
	{
		tmp->index = find_index(arr, size, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}
