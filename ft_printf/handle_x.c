/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:37:48 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/11 22:05:51 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_x(int fd, unsigned int i, char *base, int *count)
{
	if (i >= 16)
		handle_x(fd, i / 16, base, count);
	ft_putchar(fd, base[i % 16], count);
	return ;
}
