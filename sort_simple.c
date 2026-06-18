/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 12:43:24 by tireis           #+#    #+#              */
/*   Updated: 2026/06/15 18:59:24 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(a, bench);
	else if (top > mid && mid > bot)
	{
		ra(a, bench);
		sa(a, bench);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, bench);
	else if (top > mid && mid < bot && top > bot)
		ra(a, bench);
}

int	get_pos_of_index(t_stack *stack, int target_index)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->index == target_index)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	push_min_to_b(t_stack **a, t_stack **b, int target_index,
		t_bench *bench)
{
	int	size;
	int	pos;

	pos = get_pos_of_index(*a, target_index);
	size = ft_stacksize(*a);
	while (pos != 0 && pos != -1)
	{
		if (pos <= size / 2)
			ra(a, bench);
		else
			rra(a, bench);
		pos = get_pos_of_index(*a, target_index);
	}
	pb(a, b, bench);
}

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	target;

	target = 0;
	size = ft_stacksize(*a);
	if (size == 2)
	{
		sa(a, bench);
		return ;
	}
	while (size > 3)
	{
		push_min_to_b(a, b, target, bench);
		target++;
		size = ft_stacksize(*a);
	}
	sort_three(a, bench);
	while (*b != NULL)
		pa(a, b, bench);
}
