/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algos.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 13:09:41 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 14:03:22 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_logic(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->prev = NULL;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push_logic(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push_logic(b, a);
	write(1, "pb\n", 3);
}
/*
int	main(void)
{
	t_stack	*stack_a;
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack	*stack_b;
	t_stack	*node4;
	t_stack	*node5;
	t_stack	*node6;
}*/
