/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:25 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:25:52 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	num;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	num = dest_length;
	if (dest_length >= size)
		return (src_length + size);
	else
	{
		while (*dest)
			dest++;
		while (*src && num < size - 1)
		{
			*dest++ = *src++;
			num++;
		}
		*dest = '\0';
		return (dest_length + src_length);
	}
}
