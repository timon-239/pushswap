/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap_algos.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:40:20 by tireis           #+#    #+#              */
/*   Updated: 2026/05/13 17:00:09 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_stack_sa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_stacksize(stack) < 2)
		return (NULL);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}
