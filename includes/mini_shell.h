/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:38:56 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/27 12:38:32 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../sources/libft/libft.h"
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

extern char	**environ;

typedef struct s_cmd
{
	char	**cmds;
	char	**redirs;
	char	**targets;
	int		status;
}				t_cmd;

// built-ins
void		ft_echo(char **args);
void		ft_cd(char *path);
void		ft_pwd(void);
void		ft_env(char **environ);
void		ft_export(char **args);
void		ft_unset(char **args);

// utils
void		free_array(char **arr);
void		clear_env_node(char *arg);
void		ft_export_node(char *arg);
int			run_with_pipe(t_cmd cmd);
void		run_wout_pipe(t_cmd cmd);
void		run_with_execve(t_cmd cmd);
char		*find_path(char *cmd, char **paths);
int			ft_strstr(const char *s1, const char *s2);
int			vector_len(char **cmd);
void		close_fds(int **fd);
char		**ft_split_cmds(char const *s);
char		**idx_redir(char const *s);
void		dist_redirs(t_cmd command);
void		find_eof(char *str);
void		parse_cmd(char *cmd);
void		l_than(char *file);
void		ll_than(char *file);
void		g_than(char *file);
void		gg_than(char *file);
int			check_for_redir(char *cmd);
int			update_status(int new_val, int x, char *str);
void		run_shell(t_cmd cmd, char *history);
void		shandler(int signal);
void		file_creator(t_cmd command);
int			**open_fds(t_cmd cmd, int **fd);
void		dist_pipe(t_cmd cmd, int **fd, int *pid);
void		duplicate_fds(int **fd, t_cmd cmd, int i, int j);
int			red_count(char *str);
char		**make_redir(char **redirs, char const *s);
void		free_env(char *arg);
int			is_alnum(char *str);
int			where_env(char *s2);
char		**shell_split(char *str, char sep);
int			is_quote(char c);
int			quote_state(char *str, int pos);
int			char_count(char *str, char c);

// expansion
int			is_meta(int c);
char		*ft_strjoin2(char *s1, char const *s2);
char		*append_char(char *str, char c);
char		*check_env(char *str);
char		*expand_value(char *arg, int *index);
void		get_value(char *arg, char **new, int *index);
char		*interpret_arg(char *arg, int which);
void		expansion(t_cmd *cmd);
char		**splitter(char *str, char sep, int i, int j);

// syntax control
int			determine_syntax(char *str, int i);
int			check_right(int pos, char *str);
int			check_right_r(int pos, char *str);
int			check_for_gr_le_signs(char *str, int len, int i);
int			check_for_pipe_syntax(char *str, int i);
int			check_syntax(char *str);
int			char_count(char *str, char c);
#endif