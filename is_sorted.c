/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   is_sorted.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/21 13:53:58 by tireis           #+#    #+#              */
/*   Updated: 2026/05/21 14:34:13 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
/*#include <stdio.h>

int	main(void)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;
	t_stack	*stack_a;

	n1 = ft_stacknew(10);
	n2 = ft_stacknew(20);
	n3 = ft_stacknew(30);
	n1->next = n2;
	n2->prev = n1;
	n2->next = n3;
	n3->prev = n2;
	stack_a = n1;
	if (is_sorted(stack_a))
		printf("Ist schon sortiert");
	else
		printf("ist nicht sortiert");
	ft_freestack(&stack_a);
	return (0);
}*/
