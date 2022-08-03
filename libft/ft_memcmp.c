/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:07:56 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:22:34 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*u_s1 > *u_s2)
			return (*u_s1 - *u_s2);
		else if (*u_s1 < *u_s2)
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
	}
	return (0);
}
