/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:27:39 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/11 22:06:57 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
# include <stdarg.h>

int		ft_printf(int fd, const char *format, ...);

void	ft_putchar(int fd, char c, int *count);
void	handle_i(int fd, int i, int *count);
void	handle_p(int fd, void *ptr, char *base, int *count);
void	handle_s(int fd, char *s, int *count);
void	handle_x(int fd, unsigned int i, char *base, int *count);
void	handle_u(int fd, unsigned int i, char *base, int *count);
void	handle_f(int fd, double n, int *count);

#endif
