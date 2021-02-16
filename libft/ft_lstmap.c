/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:24:47 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 17:16:25 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	(void)(*del);
	new = ft_lstnew((*f)(lst->content));
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew((*f)(lst->content));
		new = new->next;
	}
	return (tmp);
}
