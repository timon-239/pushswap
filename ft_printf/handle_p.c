/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:21:31 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/29 11:10:46 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_ul(int fd, unsigned long l, char *base, int *count)
{
	if (l >= 16)
		handle_ul(fd, l / 16, base, count);
	ft_putchar(fd, base[l % 16], count);
}

void	handle_p(int fd, void *ptr, char *base, int *count)
{
	unsigned long	l;

	if (ptr == 0)
	{
		handle_s(fd, "(nil)", count);
		return ;
	}
	handle_s(fd, "0x", count);
	l = (unsigned long)ptr;
	handle_ul(fd, l, base, count);
	return ;
}
