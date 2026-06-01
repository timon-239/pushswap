/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 12:43:24 by tireis           #+#    #+#              */
/*   Updated: 2026/06/01 14:35:44 by tireis          ###   ########.fr        */
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
	if (top == 1 && mid == 0 && bot == 2)
		sa(a);
	else if (top == 2 && mid == 1 && bot == 0)
	{
		ra(a);
		sa(a);
	}
	else if (top == 0 && mid == 2 && bot == 1)
	{
		sa(a);
		ra(a);
	}
	else if (top == 1 && mid == 2 && bot == 0)
		rra(a);
	else if (top == 2 && mid == 0 && bot == 1)
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

	pos = get_pos_of_index(*a, 0);
	size = ft_stacksize(*a);
	while (pos != 0)
	{
		if (pos <= size / 2) /*FALLS OBERE HÄLFTE DES STAKCS RA*/
			ra(a);
		else
			rra(a);
		pos = get_pos_of_index(*a, 0);
	}
	pb(a, b);
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
	{
		push_min_to_b(a, b, 0);
		sort_three(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		push_min_to_b(a, b, 0);
		push_min_to_b(a, b, 1);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
