/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   lst_utils_2.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:32:35 by tireis           #+#    #+#              */
/*   Updated: 2026/05/21 14:49:02 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->index = -1;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

float	disorder_metric(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	int		size;
	t_stack	*current;

	size = ft_stacksize(a);
	mistakes = 0;
	total_pairs = 0;
	if (size <= 1)
		return (0);
	while (a->next != NULL && current->next != NULL)
	{
		current = a->next;
		total_pairs += 1;
		if (a->value > current->value)
			mistakes += 1;
		a = a->next;
	}
	return (mistakes / total_pairs);
}