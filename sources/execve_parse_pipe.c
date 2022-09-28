/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_parse_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:28:06 by merkol            #+#    #+#             */
/*   Updated: 2022/09/27 12:49:21 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

char	*get_path(t_cmd cmd)
{
	char	*path;
	char	**paths;

	path = NULL;
	if (getenv("PATH") && !ft_strchr(getenv("PATH"), ':'))
	{
		update_status(1, 0, "command not found\n");
		return (NULL);
	}
	paths = ft_split(getenv("PATH"), ':');
	if (ft_strchr(cmd.cmds[0], '/'))
		path = ft_strdup(cmd.cmds[0]);
	else
	{
		if (!getenv("PATH"))
		{
			update_status(1, 0, "command not found\n");
			return (NULL);
		}
		path = find_path(cmd.cmds[0], paths);
	}
	if (paths)
		free_array(paths);
	return (path);
}

void	run_with_execve(t_cmd cmd)
{
	int		pid;
	char	*path;

	path = get_path(cmd);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmd.cmds, environ) == -1)
		{
			update_status(1, 1, "Command not found: ");
			printf("%s\n", cmd.cmds[0]);
		}
		exit(1);
	}
	wait(&cmd.status);
	update_status(cmd.status, 0, NULL);
	free(path);
}

t_cmd	add_to_first(char *cmd)
{
	t_cmd	command;
	char	**temp2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	command.cmds = ft_split_cmds(cmd);
	while (command.cmds[++i])
	{
		temp2 = shell_split(command.cmds[i], 32);
		if (temp2[1])
		{
			while (temp2[++j])
			{
				command.cmds[0] = ft_strjoin(command.cmds[0], " ");
				command.cmds[0] = ft_strjoin(command.cmds[0], temp2[j]);
			}
			free(command.cmds[i]);
			command.cmds[i] = ft_strdup(temp2[0]);
			j = 0;
		}
		free_array(temp2);
	}
	return (command);
}

void	parse_cmd(char *cmd)
{
	t_cmd	command;
	t_cmd	temp;
	int		pid;

	pid = 0;
	command = add_to_first(cmd);
	temp.cmds = shell_split(command.cmds[0], 32);
	expansion(&temp);
	expansion(&command);
	command.redirs = idx_redir(cmd);
	pid = fork();
	if (pid == 0)
	{
		dist_redirs(command);
		run_with_execve(temp);
		exit (0);
	}
	wait (NULL);
	free_array(command.cmds);
	free_array(command.redirs);
	free_array(temp.cmds);
}

int	run_with_pipe(t_cmd cmd)
{
	int		**fd;
	int		*pid;
	int		i;

	i = -1;
	fd = malloc(sizeof(int *) * vector_len(cmd.cmds) + 1);
	pid = malloc(sizeof(int) * vector_len(cmd.cmds) + 1);
	fd = open_fds(cmd, fd);
	dist_pipe(cmd, fd, pid);
	close_fds(fd);
	i = -1;
	while (++i < vector_len(cmd.cmds))
		waitpid (pid[i], &cmd.status, 0);
	i = 0;
	while (i <= vector_len(cmd.cmds))
		free(fd[i++]);
	free(fd);
	free(pid);
	return (0);
}
