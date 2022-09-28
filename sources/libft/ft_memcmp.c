/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <furkan_tuncer@yahoo.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:54:43 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/15 14:18:58 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
