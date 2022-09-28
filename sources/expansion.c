/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:25:35 by merkol            #+#    #+#             */
/*   Updated: 2022/09/26 11:25:36 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

char	*append_char(char *str, char c)
{
	char	*new;
	int		len;

	if (!str)
	{
		new = malloc(2);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	len = ft_strlen(str);
	new = (char *)malloc(len + 2);
	ft_strlcpy(new, str, len + 1);
	new[len++] = c;
	new[len] = '\0';
	free(str);
	str = NULL;
	return (new);
}

char	*check_env(char *str)
{
	char	*temp;

	temp = NULL;
	if (!getenv(str))
	{
		free(str);
		return (NULL);
	}
	temp = ft_strdup(getenv(str));
	free(str);
	return (temp);
}

char	*expand_value(char *arg, int *index)
{
	int		i;
	char	*variable;

	i = -1;
	variable = (char *)malloc(1 * ft_strlen(arg));
	while (arg[++(*index)] && !is_meta(arg[*index]))
	{
		if (arg[*index] == '?')
		{
			(*index)++;
			free(variable);
			return (ft_itoa(update_status(0, -10, NULL)));
		}
		else
			variable[++i] = arg[*index];
	}
	variable[++i] = 0;
	return (check_env(variable));
}

void	get_value(char *arg, char **new, int *index)
{
	char	*dsign;

	dsign = expand_value(arg, index);
	if (dsign)
	{
		*new = ft_strjoin2(*new, dsign);
		free(dsign);
	}
}

char	*interpret_arg(char *arg, int which)
{
	int		i;
	int		counter;
	char	*new;

	i = -1;
	counter = 0;
	new = NULL;
	while (arg[++i])
	{
		if (counter % 2 == 0)
			which = 0;
		while (arg[i] == '$' && !is_meta(arg[i + 1]) && which != 39)
			get_value(arg, &new, &i);
		if (!arg[i])
			break ;
		if (counter % 2 == 0 && arg[i] != which \
			&& (arg[i] == 34 || arg[i] == 39))
				which = arg[i];
		if (arg[i] != which)
			new = append_char(new, arg[i]);
		else
			counter++;
	}
	free(arg);
	return (new);
}
