/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:49:11 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/05 11:55:54 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	i = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dst;
	if (n == 0 || dst == src)
		return (dest_char);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest_char);
}
