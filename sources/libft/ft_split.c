/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:27:04 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/15 10:59:59 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

static int	charcnt(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && (*s != c))
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		splidx;

	if (!s)
		return (0);
	splidx = 0;
	spl = malloc(sizeof(char *) * word(s, c) + 1);
	if (!spl)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		spl[splidx] = ft_substr(s, 0, charcnt(s, c));
		splidx++;
		s = s + charcnt(s, c);
	}
	spl[splidx] = NULL;
	return (spl);
}
