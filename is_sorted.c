/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   is_sorted.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 13:53:58 by tireis           #+#    #+#              */
/*   Updated: 2026/05/21 14:03:51 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*a;

	if (!stack == NULL || !stack->next == NULL)
		return (1);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
