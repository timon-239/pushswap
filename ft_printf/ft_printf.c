/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:25:37 by eboualla          #+#    #+#             */
/*   Updated: 2026/06/15 19:05:05 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	check_conv(int fd, va_list *args, char c, int *count)
{
	if (c == 'c')
		ft_putchar(fd, va_arg(*args, int), count);
	else if (c == 's')
		handle_s(fd, va_arg(*args, char *), count);
	else if (c == 'p')
		handle_p(fd, va_arg(*args, void *), "0123456789abcdef", count);
	else if (c == 'd' || c == 'i')
		handle_i(fd, va_arg(*args, int), count);
	else if (c == 'u')
		handle_u(fd, va_arg(*args, unsigned int), "0123456789", count);
	else if (c == 'x')
		handle_x(fd, va_arg(*args, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		handle_x(fd, va_arg(*args, unsigned int), "0123456789ABCDEF", count);
	else if (c == '%')
		ft_putchar(fd, '%', count);
	else if (c == 'f')
		handle_f(fd, va_arg(*args, double), count);
	else
	{
		ft_putchar(fd, '%', count);
		ft_putchar(fd, c, count);
	}
	return ;
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			check_conv(fd, &args, format[i + 1], &count);
			i++;
		}
		else if (format[i] == '%' && !format[i + 1])
			return (va_end(args), -1);
		else
			ft_putchar(fd, format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int				a;
	char			c;
	char			*s;
	unsigned int	hex;
	unsigned int	heX;
	unsigned int	u;
	int				res1;
	int				res2;
	void			*ptr;
	int				meins;
	int				original;
int			mein1 = ft_printf("abc%");
int			res1 = printf("abc%");
int			mein2 = ft_printf("ab%y");
int			res2 = printf("ab%y");

	hex = 44;
	heX = 44;
	u = 123456;
	a = 0;
	c = 'e';
	s = "Hello";
	ptr = NULL;
	res1 = ft_printf("int%d, char%c, string%s, hex%x, heX%X, u%u, void%p also
			%%", a, c, s, hex, heX, u, ptr);
	printf("\n");
	res2 = printf("int%d, char%c, string%s, hex%x, heX%X, u%u, void%p also %%",
			a, c, s, hex, heX, u, ptr);
	printf("\n");
	printf("return (1 = %d, return (2 = %d", res1, res2)));
	printf("\n");
	return (0);
	meins = ft_printf("hallo %z hallo");
	printf("\n");
	original = printf("hallo %z hallo");
	printf("\n");
	printf("mein = %d,\n original = %d", meins, original);
printf("\n");
printf("\n");
printf("mein1: %d,\nres1: %d", mein1, res1);
printf("\n");
printf("\n");
printf("\n");
printf("mein2: %d,\n res2: %d", mein2, res2);
}
*/
