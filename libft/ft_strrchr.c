/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:40 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:28:24 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			len;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (len--)
	{
		if (*(s + len) == ch)
			return ((char *)(s + len));
	}
	return (NULL);
}
