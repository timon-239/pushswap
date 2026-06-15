/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_medium.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/03 12:41:28 by tireis           #+#    #+#              */
/*   Updated: 2026/06/08 13:14:45 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt_simple(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i * i <= n)
	{
		if (i > 46340)
			break ;
		i++;
	}
	return (i - 1);
}

static int	get_chunk_size(int size)
{
	int	chunk;

	if (size <= 0)
		return (0);
	chunk = ft_sqrt_simple(size);
	if (chunk <= 1)
		return (1);
	return (chunk);
}

int	get_max_index_value(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_to_b_in_chunks(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = get_chunk_size(ft_stacksize(*a));
	while (ft_stacksize(*a) > 0)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_val;
	int	pos;
	int	size;

	push_to_b_in_chunks(a, b, bench);
	while (ft_stacksize(*b) > 0)
	{
		max_val = get_max_index_value(*b);
		pos = get_pos_of_index(*b, max_val);
		size = ft_stacksize(*b);
		while (pos != 0)
		{
			if (pos <= size / 2)
				rb(b, bench);
			else
				rrb(b, bench);
			pos = get_pos_of_index(*b, max_val);
		}
		pa(a, b, bench);
	}
}
