/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 12:43:24 by tireis           #+#    #+#              */
/*   Updated: 2026/06/05 14:25:27 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		ra(a);
		sa(a);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
	else if (top > mid && mid < bot && top > bot)
		ra(a);
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
void	push_min_to_b(t_stack **a, t_stack **b, int target_index)
{
	int	size;
	int	pos;

	pos = get_pos_of_index(*a, target_index);
	size = ft_stacksize(*a);
	while (pos != 0)
	{
		if (pos <= size / 2) /*FALLS OBERE HÄLFTE DES STACKS RA*/
			ra(a);
		else
			rra(a);
		pos = get_pos_of_index(*a, target_index);
	}
	pb(a, b);
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	size;
	int target;

	target = 0;
	size = ft_stacksize(*a);
	if (size == 2)
	{
		sa(a);
		return ;
	}
	while (size > 3)	
	{
		push_min_to_b(a, b, target);
		target++;
		size = ft_stacksize(*a);
	}
	sort_three(a);
	while (*b  != NULL)
		pa(a, b);
}
