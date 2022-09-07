/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:06:11 by epark             #+#    #+#             */
/*   Updated: 2022/09/07 15:42:56 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	callspecifier(char c, va_list args)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(args, int)));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long long);
		if (p == 0)
			return (ft_putstr("0x0"));
		else
			return (ft_putstr("0x") + ft_putpointer(p));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		sum;

	if (format == 0)
		return (0);
	i = 0;
	sum = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 0)
				break ;
			sum += callspecifier(format[i], args);
		}
		else
			sum += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (sum);
}
