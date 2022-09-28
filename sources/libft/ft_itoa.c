/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:30:14 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/21 16:43:00 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int a, int b)
{
	if (a == 0)
		return (b + 1);
	else if (a < 0)
	{
		while (a)
		{
			a /= 10;
			b++;
		}
		return (b + 1);
	}
	else if (a > 0)
	{
		while (a)
		{
			a /= 10;
			b++;
		}
		return (b);
	}
	return (0);
}

static long int	ft_negative(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		i;
	int				size;

	size = ft_size(n, 0);
	i = ft_negative((long int)n);
	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	*(s + size--) = '\0';
	while (i > 0)
	{
		*(s + size--) = (i % 10) + '0';
		i /= 10;
	}
	if (size == 0 && s[1] == '\0')
		*(s + size) = '0';
	if (size == 0 && s[1] != '\0')
		*(s + size) = '-';
	return (s);
}
