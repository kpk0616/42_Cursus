/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:06:11 by epark             #+#    #+#             */
/*   Updated: 2022/09/05 19:14:23 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	callspecifier(char c, va_list args)
{
	unsigned long long	p; // unsigned long long 을 쓰는 이유?

	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int))); // int 로 받는 이유?
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x' || c == 'X') // unsigned 16진수 출력 - x / X : 진수 대소문자 차이
		return (ft_puthex(va_arg(args, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i') // 10진수 정수 출력
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'u') // unsigned 10진수 출력
		return (ft_uitoa(va_arg(args, int)));
	else if (c == 'p') // 포인터 변수 주소 출력
	{
		p = va_arg(args, unsigned long long);
		if (p == 0)
			return (ft_putstr("0x0"));
		else
			return (ft_putstr("0x") + ft_putpointer(p));
	}
	return (0);
}

int	ft_printf(const char *format, ...) // ex: printf("Hello %s", "Minsoo"); 가변 인자는 "Hello %s" 에서 시작, va_arg 시 "Minsoo" 로 옮겨짐
{
	va_list	args;
	int		i;
	int		sum;

	if (format == 0)
		return (0);
	i = 0;
	sum = 0;
	va_start(args, format); // 가변 인자가 첫 인자인 format 에서 시작하도록 함
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 0)
				break;
			sum += callspecifier(format[i], args);
		}
		else
			sum += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (sum);
}

#include <stdio.h>
int main()
{
	// char* str = "abc";
	int n = ft_printf("%p\n", "");
	printf("%p\n", "");
	printf("n: %d", n);
}