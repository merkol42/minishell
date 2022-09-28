/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:26:27 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/27 12:52:46 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		free (arr[i]);
		arr[i] = NULL;
	}
	free (arr);
	arr = NULL;
}

int	ft_strstr(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(s1) == (int)ft_strlen(s2))
	{
		while (s1[i] && s1[i] == s2[i])
			i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}

char	*find_path(char *cmd, char **paths)
{
	struct dirent	*vals;
	DIR				*curr_path;
	int				i;
	char			*ret;

	i = -1;
	while (paths[++i] && opendir(paths[i]))
	{
		curr_path = opendir(paths[i]);
		vals = readdir(curr_path);
		while (vals != NULL)
		{
			if (ft_strstr(vals->d_name, cmd))
			{
				paths[i] = ft_strjoin(paths[i], "/");
				closedir(curr_path);
				paths[i] = ft_strjoin(paths[i], cmd);
				ret = ft_strdup(paths[i]);
				return (ret);
			}
			vals = readdir(curr_path);
		}
		closedir(curr_path);
	}
	return (NULL);
}

int	vector_len(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

void	close_fds(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}
