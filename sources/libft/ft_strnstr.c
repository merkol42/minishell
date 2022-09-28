/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:40:59 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/23 15:45:58 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	if (*needle == '\0')
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (*haystack && len-- >= nlen)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
