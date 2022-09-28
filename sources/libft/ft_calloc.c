/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <furkan_tuncer@yahoo.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:09 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/07 14:31:12 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	pt = (void *)malloc(size * count);
	if (!pt)
		return (pt);
	ft_bzero(pt, (size * count));
	return (pt);
}
