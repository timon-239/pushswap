/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap_logic.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:40:20 by tireis           #+#    #+#              */
/*   Updated: 2026/06/01 14:05:56 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_logic(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_stacksize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

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
	ft_swap_logic(stack_b);
	write(1, "ss\n", 3);
}
/*#include <stdio.h>

int	main(void)
{
	t_stack	*a;
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack	*tmp;

	node1 = ft_stacknew(1);
	node2 = ft_stacknew(2);
	node3 = ft_stacknew(3);
	a = node1;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	printf("\nVOR SA:\n");
	tmp = a;
	while (tmp)
	{
		printf("VALUE : %d\n, SELF : %p\n, NEXT : %p \n, PREV : %p\n",
			tmp->value, (void *)tmp, (void *)tmp->next, (void *)tmp->prev);
		tmp = tmp->next;
	}
	ft_stack_sa(&a);
	printf("\nNACH SA:\n");
	tmp = a;
	while (tmp)
	{
		printf("VALUE : %d\n, SELF : %p\n, NEXT : %p \n, PREV : %p\n",
			tmp->value, (void *)tmp, (void *)tmp->next, (void *)tmp->prev);
		tmp = tmp->next;
	}
	return (0);
}*/
