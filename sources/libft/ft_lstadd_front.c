/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <furkan_tuncer@yahoo.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:18:05 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/14 13:15:05 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
