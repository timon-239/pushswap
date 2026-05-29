/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/18 14:03:04 by tireis           #+#    #+#              */
/*   Updated: 2026/05/29 15:42:00 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack == NULL || stack->next == NULL)
		return (0);
	current = stack;
	while (current->next != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->value == current->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
/*
#include <stdio.h>

int main (void){
	t_stack *node1;
	t_stack *node2;
	t_stack *node3;
	t_stack *node4;
	t_stack *node5;
	t_stack *a;

	node1 = ft_stacknew(9);
	node2 = ft_stacknew(4);
	node3 = ft_stacknew(0);
	node4 = ft_stacknew(2);
	node5 = ft_stacknew(0);

	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	node4->next = node5;
	node5->prev = node4;
	a = node1;
	if(has_duplicates(a))
		printf("hat duplicates");
	else
		printf("hat keine");
	ft_freestack(&a);
}
*/
