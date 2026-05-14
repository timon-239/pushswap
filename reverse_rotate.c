/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 14:34:02 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 15:01:25 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_ro_logic(stack_t **stack)
{
	t_stack	*prev_to_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_stacklast(stack);
	prev_to_last = last->prev;
	prev_to_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}
