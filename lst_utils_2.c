/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   lst_utils_2.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:32:35 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 12:44:59 by tireis          ###   ########.fr        */
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
	ptr->stack = -1;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
