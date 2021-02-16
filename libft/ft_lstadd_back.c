/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:54:04 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:22:38 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!(*alst))
		(*alst) = new;
	else
	{
		ptr = ft_lstlast(*alst);
		ptr->next = new;
		new->next = NULL;
	}
}
