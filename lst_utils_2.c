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
