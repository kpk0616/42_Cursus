/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:37 by epark             #+#    #+#             */
/*   Updated: 2022/07/13 21:27:25 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		j = 0;
		if (*(haystack + i + j) == '\0')
			return (NULL);
		while (*(haystack + i + j) == *(needle + j) && i + j < len)
		{
			j++;
			if (*(needle + j) == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
