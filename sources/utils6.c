/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:05 by merkol            #+#    #+#             */
/*   Updated: 2022/09/27 11:52:57 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

int	quote_state(char *str, int pos)
{
	int	ret;
	int	i;
	int	quote;

	ret = 0;
	i = 0;
	quote = 0;
	while (str[i] && i < pos)
	{
		if (!quote && (str[i] == 34 || str[i] == 39))
			quote = str[i];
		if (quote == str[i] && ret == 0)
			ret = 1;
		else if (quote == str[i] && ret == 1)
			ret = 0;
		i++;
	}
	return (ret);
}

int	char_count(char *str, char c)
{
	int	i;
	int	ret;

	if (!str)
		return (0);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == c && !quote_state(str, i))
			ret++;
		i++;
	}
	return (ret);
}

int	is_alnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
