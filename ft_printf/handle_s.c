/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:52:39 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/11 13:43:22 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_s(int fd, char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(fd, *s, count);
		s++;
	}
	return ;
}
