/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:13:10 by epark             #+#    #+#             */
/*   Updated: 2022/09/05 18:52:58 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counthex(unsigned long long num)
{
	int	count;

	count = 1;
	while(num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static void	putnbr_base(unsigned long long num, char *base)
{
	if (num >= 16)
		putnbr_base((num / 16), base);
	ft_putchar(base[num % 16]);
}

int	ft_puthex(int n, char c)
{
	char	*base;
	int		count;
	unsigned int	num;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	num = (unsigned int)n;
	putnbr_base(num, base);
	count += counthex(num);
	return (count);
}

int	ft_putpointer(unsigned long long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;

	putnbr_base(num, base);
	count += counthex(num);
	return (count);
}