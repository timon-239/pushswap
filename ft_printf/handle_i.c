/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 08:40:03 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/11 13:43:08 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_i(int fd, int i, int *count)
{
	long	n;

	n = i;
	if (n < 0)
	{
		ft_putchar(fd, '-', count);
		n = -n;
	}
	if (n >= 10)
		handle_i(fd, n / 10, count);
	ft_putchar(fd, (n % 10) + '0', count);
}

static void	print_2digits(int fd, long long n, int *count)
{
	int	div;

	div = 10;
	while (div > 0)
	{
		ft_putchar(fd, (n / div) + '0', count);
		n %= div;
		div /= 10;
	}
}

void	handle_f(int fd, double n, int *count)
{
	long long	intpart;
	long long	fracpart;

	if (n < 0)
	{
		ft_putchar(fd, '-', count);
		n = -n;
	}

	n += 0.005;
	intpart = (long long)n;
	fracpart = (long long)((n - intpart) * 100);

	handle_i(fd, intpart, count);
	ft_putchar(fd, '.', count);
	print_2digits(fd, fracpart, count);
}