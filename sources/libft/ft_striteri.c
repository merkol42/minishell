/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:50:36 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/10 14:11:29 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	i;

	i = 0;
	if (!(s))
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
