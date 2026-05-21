/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   cooridnation.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 14:50:44 by tireis           #+#    #+#              */
/*   Updated: 2026/05/21 14:58:30 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a)
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
