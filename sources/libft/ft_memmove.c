/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:25:38 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/05 11:55:04 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest_char;
	unsigned char	*temp;
	int				i;

	i = (int)len;
	temp = (unsigned char *)src;
	dest_char = (unsigned char *)dst;
	if (dest_char > temp)
	{
		while (--i >= 0)
			dest_char[i] = temp[i];
	}
	else
		ft_memcpy(dest_char, temp, len);
	return (dest_char);
}
