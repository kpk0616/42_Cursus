/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:08 by epark             #+#    #+#             */
/*   Updated: 2022/07/20 22:27:02 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char str, char c)
{
	if (str == '\0' || str == c)
		return (1);
	return (0);
}

static void	write_word(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (is_separator(*(src + i), c) == 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
}

static void	free_mem(char **str, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
		free(str[i++]);
	free(str);
}

static void	write_result(char **result, char *str, char c)
{
	int	i;
	int	j;
	int	w_index;

	w_index = 0;
	i = 0;
	while (*(str + i))
	{
		if (is_separator(*(str + i), c) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(*(str + i + j), c) == 0)
				j++;
			result[w_index] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[w_index])
				free_mem(&result[w_index], w_index);
			write_word(result[w_index], str + i, c);
			i += j;
			w_index++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		word_count;
	char	**result;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	str = (char *)s;
	word_count = 0;
	while (*(str + k))
	{
		if (is_separator(*(str + k + 1), c) == 1 && \
		is_separator(*(str + k), c) == 0)
			word_count++;
		k++;
	}
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	result[word_count] = 0;
	write_result(result, str, c);
	return (result);
}
