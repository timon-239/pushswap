/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:32:35 by tireis           #+#    #+#              */
/*   Updated: 2026/06/16 16:10:48 by eboualla         ###   ########.fr       */
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
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

int	parse_token(char *str, t_stack **a)
{
	long	val;
	t_stack	*new;

	if (!is_num(str))
		return (0);
	val = ft_atol(str);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	new = ft_stacknew((int)val);
	if (!new)
		return (0);
	ft_stackadd_back(a, new);
	return (1);
}
