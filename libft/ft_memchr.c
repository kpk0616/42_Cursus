/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:16:58 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:21:58 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ch;

	ch = (unsigned char *)src;
	while (n-- > 0)
	{
		if (*ch == (unsigned char)c)
			return (ch);
		ch++;
	}
	return (0);
}
