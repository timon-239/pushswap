/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algos.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/14 13:09:41 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 13:12:15 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	ft_swap_logic(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	ft_swap_logic(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_logic(stack_a);
	ft_swap_logic(btack_b);
	write(1, "ss\n", 3);
}
