/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:26:50 by merkol            #+#    #+#             */
/*   Updated: 2022/09/27 11:52:58 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

int	where_env(char *s2)
{
	int		i;
	char	**temp;
	char	**env;

	i = 0;
	temp = ft_split(s2, '=');
	while (environ[i])
	{
		env = ft_split(environ[i], '=');
		if (ft_strstr(env[0], temp[0]))
		{
			free_array(env);
			free_array(temp);
			return (i);
		}
		free_array(env);
		i++;
	}
	free_array(temp);
	return (-1);
}

int	is_quote(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

void	split_quote(char *str, char **new, char sep, int *i)
{
	int	a;

	a = 0;
	while (str[*i])
	{
		if (!a && is_quote(str[*i]))
		{
			a = str[*i];
			sep = 0;
		}
		if (str[*i] != sep)
			new[0] = append_char(new[0], str[*i]);
		else
			break ;
		if (a && str[*i] != a)
			sep = 0;
		else if (!a)
			sep = 32;
		(*i)++;
	}
}

char	**splitter(char *str, char sep, int i, int j)
{
	char	**new;
	int		flag;
	int		a;

	flag = -1;
	a = 0;
	new = (char **)ft_calloc(20, 8);
	while (str[i])
	{
		split_quote(str, &new[j], sep, &i);
		while (str[i] == 32)
			i++;
		j++;
	}
	return (new);
}

char	**shell_split(char *str, char sep)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strtrim(str, " ");
	new = splitter(str, sep, i, j);
	free(str);
	return (new);
}
