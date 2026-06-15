/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate_logic.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 14:05:13 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 14:27:35 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_logic(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	first = *stack;
	if (!first || !first->next)
		return ;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = ft_stacklast(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	ft_rotate_logic(a);
	bench->ra++;
	bench->total++;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b, t_bench *bench)
{
	ft_rotate_logic(b);
	bench->rb++;
	bench->total++;
	ft_printf(1, "rb\n");
}
