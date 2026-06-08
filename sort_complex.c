/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:07:10 by eboualla          #+#    #+#             */
/*   Updated: 2026/06/08 15:09:52 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(int max_index)
{
	int bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void sort_complex(t_stack **a, t_stack **b)
{
	int i;
	int j;
	int size;
	int max_index;
	int max_bits;

	i = 0;
	max_index = get_max_index_value(*a);
	max_bits = get_max_bits(max_index);
	size = ft_stacksize(*a);
	while (i < max_bits)
	{
		j = 0;
		while(j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while(*b)
			pa(a, b);
		i++;
	}
}
