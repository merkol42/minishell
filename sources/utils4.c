/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:26:33 by merkol            #+#    #+#             */
/*   Updated: 2022/09/26 11:26:34 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

void	duplicate_fds(int **fd, t_cmd cmd, int i, int j)
{
	if (i > 0)
		dup2(fd[j - 1][0], STDIN_FILENO);
	if (cmd.cmds[i + 1] != NULL)
		dup2(fd[j][1], STDOUT_FILENO);
}

void	dist_pipe(t_cmd cmd, int **fd, int *pid)
{
	int		j;
	int		i;
	t_cmd	holder;

	i = -1;
	j = 0;
	while (cmd.cmds[++i])
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			duplicate_fds(fd, cmd, i, j);
			close_fds(fd);
			if (!check_for_redir(cmd.cmds[i]))
				parse_cmd(cmd.cmds[i]);
			else
			{
				holder.cmds = shell_split(cmd.cmds[i], 32);
				expansion(&holder);
				run_wout_pipe(holder);
			}
			exit(0);
		}
		j++;
	}	
}

char	**idx_redir(char const *s)
{
	char	**redirs;

	redirs = malloc(sizeof(char *) * red_count((char *)s));
	if (!redirs)
		return (0);
	redirs = make_redir(redirs, s);
	return (redirs);
}

int	is_meta(int c)
{
	if (c == '\0')
		return (1);
	if (c == '?')
		return (0);
	if (c == '_')
		return (0);
	if (!ft_isalnum(c))
		return (c);
	return (0);
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}
