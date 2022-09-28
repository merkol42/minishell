/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:30:21 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/11 18:17:35 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	i;

	i = 0;
	if (!(s))
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
