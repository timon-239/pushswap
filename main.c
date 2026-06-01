/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/18 14:27:59 by tireis           #+#    #+#              */
/*   Updated: 2026/06/01 14:09:42 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		val;
	t_stack	*new;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
		{
			write(2, "Error\n", 6);
			ft_freestack(&a);
			return (1);
		}
		val = ft_atoi(argv[i]);
		new = ft_stacknew(val);
		if (!new)
		{
			ft_freestack(&a);
			return (1);
		}
		ft_stackadd_back(&a, new);
		i++;
	}
	if (has_duplicates(a))
	{
		write(2, "Error\n", 6);
		ft_freestack(&a);
		return (1);
	}
	assign_index(a);
	if (!is_sorted(a))
	{
		if (ft_stacksize(a) <= 5)
			sort_simple(&a, &b);
		else /* sortbig*/
		{
			write(2, "Error\n", 6);
			ft_freestack(&a);
			ft_freestack(&b);
			return (1);
		}
	}
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
