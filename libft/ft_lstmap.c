/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:42:36 by epark             #+#    #+#             */
/*   Updated: 2022/07/19 18:39:39 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*temp;
	t_list	*new;

	header = NULL;
	temp = lst;
	if (lst == NULL)
		return (NULL);
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		if (new == NULL)
		{
			ft_lstclear(&header, del);
			return (NULL);
		}
		ft_lstadd_back(&header, new);
		temp = temp->next;
	}
	return (header);
}
