/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/18 14:27:59 by tireis           #+#    #+#              */
/*   Updated: 2026/06/04 21:56:54 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_flag(char *argv, t_mode *mode)
{
	if (ft_strcmp(argv, "--simple") == 0)
		return (*mode = MODE_SIMPLE, 1);
	if (ft_strcmp(argv, "--medium") == 0)
		return (*mode = MODE_MEDIUM, 1);
	if (ft_strcmp(argv, "--complex") == 0)
		return (*mode = MODE_COMPLEX, 1);
	if (ft_strcmp(argv, "--adaptive") == 0)
		return (*mode = MODE_ADAPTIVE, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		val;
	t_stack	*new;
	t_mode mode;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	mode = MODE_ADAPTIVE;
	while (i < argc)
	{
		if (check_flag(argv[i], &mode))
		{
			i++;
			continue ;
		}
		if (!is_num(argv[i]))
		{
			write(2, "Error\n", 6);
			ft_freestack(&a);
			return (1);
		}
		val = ft_atol(argv[i]);
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
	float disorder = disorder_metric(a);
	ft_printf("%f\n", disorder);
	assign_index(a);
	if(!is_sorted(a))
	{
		if (mode == MODE_SIMPLE)
			sort_simple(&a, &b);
		else if (mode == MODE_MEDIUM)
			sort_medium(&a, &b);
		else if (mode == MODE_COMPLEX)
			sort_complex(&a, &b);
		else if (mode == MODE_ADAPTIVE)
		{
			if (disorder < 0.2)
				sort_simple(&a, &b);
			else if (disorder < 0.5)
				sort_medium(&a, &b);
			else
				sort_complex(&a, &b);
		}
	}
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
