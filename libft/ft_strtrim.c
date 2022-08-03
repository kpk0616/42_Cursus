/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:43 by epark             #+#    #+#             */
/*   Updated: 2022/07/19 18:46:47 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		fst;
	int		end;
	int		i;

	if (s1 == 0 || set == 0)
		return ((char *)s1);
	fst = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + fst) && ft_strchr(set, *(s1 + fst)))
		fst++;
	while (ft_strchr(set, *(s1 + end)) && fst < end)
		end--;
	str = (char *)malloc(sizeof(char) * (end - fst + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (fst <= end)
		*(str + i++) = *(s1 + fst++);
	*(str + i) = '\0';
	return (str);
}
