/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:35 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:26:52 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	c1 = (unsigned char)*s1++;
	c2 = (unsigned char)*s2++;
	while ((c1 == c2) && (*s1 || *s2) && n > 0)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (c1 - c2);
}
