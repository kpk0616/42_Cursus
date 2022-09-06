/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:50 by epark             #+#    #+#             */
/*   Updated: 2022/09/05 17:48:15 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

static long	countdigit(long num)
{
	int	digit;

	digit = 1;
	while(num > 9)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

int	ft_itoa(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		count += 1;
	}
	count += countdigit(num);
	ft_putnbr(num);
	return (count);
}

int	ft_uitoa(int n)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = (unsigned int)n;
	count += countdigit(num);
	ft_putnbr(num);
	return (count);
}