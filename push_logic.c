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

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	ft_push_logic(a, b);
	bench->pa++;
	bench->total++;
	ft_printf(1, "pa\n");
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	ft_push_logic(b, a);
	bench->pb++;
	bench->total++;
	ft_printf(1, "pb\n");
}