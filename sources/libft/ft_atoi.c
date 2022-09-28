/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:07:52 by ftuncer           #+#    #+#             */
/*   Updated: 2022/02/11 18:03:30 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	i;
	int				sign;

	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		i = (i * 10) + (*str - '0') * sign;
		str++;
		if (i > 2147483647)
			return (-1);
		if (i < -2147483648)
			return (0);
	}
	return (i);
}
