/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:29:02 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/26 15:37:25 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new_ptr;

	if (!ptr)
		return (malloc(size));
	new_ptr = malloc(size);
	ft_memmove(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void	ft_export_one(char *arg)
{
	char	**temp;
	int		i;

	i = -1;
	temp = ft_split(arg, '=');
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], temp[0], ft_strlen(temp[0])))
		{
			environ[i] = ft_strdup(arg);
			free_array(temp);
			return ;
		}
	}
	environ = ft_realloc(environ, (i + 2) * 8);
	environ[i] = ft_strdup(arg);
	environ[i + 1] = NULL;
	free_array(temp);
}

void	ft_export(char **args)
{
	int		i;

	i = 0;
	if (!args[1])
	{
		printf("\n");
		return ;
	}
	while (args[++i])
	{
		if (!ft_strchr(args[i], '=') || ft_isdigit(args[i][0]))
		{
			printf("Not a valid identifier\n");
			update_status(1, 0, NULL);
			return ;
		}
		ft_export_one(args[i]);
	}
	update_status(0, 0, NULL);
}

void	free_env(char *arg)
{
	char	**temp;
	char	*temp2;

	temp2 = NULL;
	temp = environ;
	if (where_env(arg) < 0 || where_env(arg) == -1)
		return ;
	while (*environ != NULL)
	{
		if (!where_env(arg))
			break ;
		environ++;
	}
	while (*environ != NULL)
	{
		if (*environ)
			*environ = *(environ + 1);
		environ++;
	}
	environ = temp;
}

void	ft_unset(char **args)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		update_status(1, 1, "not enough arguments\n");
		return ;
	}
	while (args[++i])
	{
		if (!is_alnum(args[i]))
			update_status(256, 0, "not a valid identifier\n");
		free_env(args[i]);
	}
}
