/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/18 14:27:59 by tireis           #+#    #+#              */
/*   Updated: 2026/06/15 18:59:58 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_flag(char *argv, t_config *cfg)
{
	if (ft_strcmp(argv, "--simple") == 0)
		return (cfg->mode = MODE_SIMPLE, 1);
	if (ft_strcmp(argv, "--medium") == 0)
		return (cfg->mode = MODE_MEDIUM, 1);
	if (ft_strcmp(argv, "--complex") == 0)
		return (cfg->mode = MODE_COMPLEX, 1);
	if (ft_strcmp(argv, "--adaptive") == 0)
		return (cfg->mode = MODE_ADAPTIVE, 1);
	if (ft_strcmp(argv, "--bench") == 0)
		return (cfg->bench = 1, 1);
	return (0);
}

static int	parse_arguments(int argc, char **argv, t_stack **a, t_config *cfg)
{
	int		i;
	long	val;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		if (check_flag(argv[i], cfg))
		{
			i++;
			continue ;
		}
		if (!is_num(argv[i]))
			return (0);
		val = ft_atol(argv[i]);
		if (val > 2147483647 || val < -2147483648)
			return (0);
		new = ft_stacknew((int)val);
		if (!new)
			return (0);
		ft_stackadd_back(a, new);
		i++;
	}
	return (1);
}

static void	sort_mode(t_stack *a, t_stack *b, t_config cfg, float disorder)
{
	t_bench	bench;

	assign_index(a);
	if (!is_sorted(a))
	{
		if (cfg.bench)
			bench_init(&bench);
		if (cfg.mode == MODE_SIMPLE)
			sort_simple(&a, &b, &bench);
		else if (cfg.mode == MODE_MEDIUM)
			sort_medium(&a, &b, &bench);
		else if (cfg.mode == MODE_COMPLEX)
			sort_complex(&a, &b, &bench);
		else
		{
			if (disorder < 0.2)
				sort_simple(&a, &b, &bench);
			else if (disorder < 0.5)
				sort_medium(&a, &b, &bench);
			else
				sort_complex(&a, &b, &bench);
		}
		if (cfg.bench)
			print_bench(&bench, disorder, cfg.mode);
	}
}

static void	init(t_config *cfg, t_stack **a, t_stack **b)
{
	cfg->mode = MODE_ADAPTIVE;
	cfg->bench = 0;
	*a = NULL;
	*b = NULL;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	float		disorder;

	if (argc < 2)
		return (0);
	init(&cfg, &a, &b);
	if (!parse_arguments(argc, argv, &a, &cfg) || has_duplicates(a))
	{
		write(2, "Error\n", 6);
		ft_freestack(&a);
		return (1);
	}
	disorder = disorder_metric(a);
	sort_mode(a, b, cfg, disorder);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
