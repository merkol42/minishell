/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:47:27 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/27 11:15:30 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

void	run_shell(t_cmd cmd, char *history)
{
	find_eof(history);
	if (char_count(history, '|'))
	{
		cmd.cmds = ft_split(history, '|');
		run_with_pipe(cmd);
		free_array(cmd.cmds);
	}
	else if (char_count(history, '<') || char_count(history, '>'))
		parse_cmd(history);
	else
	{
		cmd.cmds = shell_split(history, 32);
		expansion(&cmd);
		run_wout_pipe(cmd);
	}
}

void	shandler(int signal)
{
	if (signal == SIGINT)
	{	
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	find_eof(char *str)
{
	char	**temp;
	char	**temp2;
	char	**ret;
	char	**ret2;
	int		i;

	i = -1;
	if (char_count(str, '<'))
	{
		temp = ft_split_cmds(str);
		temp2 = idx_redir(str);
		while (temp2[++i])
		{
			if (ft_strstr(temp2[i], "<<"))
			{
				ret = ft_split(temp[i + 1], '|');
				ret2 = ft_split(temp[i + 1], 32);
				ll_than(ft_strtrim(ret2[0], " "));
				free_array(ret);
				free_array(ret2);
			}
		}
		free_array(temp);
		free_array(temp2);
	}
}

void	file_creator(t_cmd command)
{
	int	i;

	i = -1;
	while (command.redirs[++i])
	{
		if (ft_strstr(command.redirs[i], ">"))
		{
			if (access(command.cmds[i + 1], F_OK) == -1)
			{
				if (!open(command.cmds[i + 1], O_CREAT, 0666))
					perror("Create: ");
			}
		}
	}
}

int	**open_fds(t_cmd cmd, int **fd)
{
	int	j;

	j = -1;
	while (++j < vector_len(cmd.cmds))
	{
		fd[j] = malloc(sizeof(int) * 2);
		if (pipe(fd[j]) == -1)
			perror("");
	}
	fd[j] = NULL;
	return (fd);
}
