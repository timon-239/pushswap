/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 14:34:02 by tireis           #+#    #+#              */
/*   Updated: 2026/06/01 14:05:26 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_ro_logic(t_stack **stack)
{
	t_stack	*prev_to_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_stacklast(*stack);
	prev_to_last = last->prev;
	prev_to_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_ro_logic(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_ro_logic(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_ro_logic(a);
	reverse_ro_logic(b);
	write(1, "rrr\n", 4);
}
