/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/18 14:03:04 by tireis           #+#    #+#              */
/*   Updated: 2026/05/21 13:14:56 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	int		last_value;

	if (stack == NULL || stack->next == NULL)
		return (0);
	current = stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	last_value = current->value;
	current = stack;
	while (current->next != NULL)
	{
		if (current->value == last_value)
			return (1);
		current = current->next;
	}
	return (0);
}
