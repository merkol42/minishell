/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd_env_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:29:35 by merkol            #+#    #+#             */
/*   Updated: 2022/09/26 11:29:36 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

void	ft_cd(char *path)
{
	if (update_status(chdir(path), 0, NULL) < 0)
		perror("");
}

void	ft_pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, sizeof(path));
	if (!path)
	{
		update_status(1, 0, NULL);
		return ;
	}
	printf("%s\n", path);
	free(path);
}

void	ft_env(char **environ)
{
	int	i;

	i = -1;
	while (environ[++i])
		printf("%s\n", environ[i]);
}

void	ft_echo(char **args)
{
	int		i;

	i = 0;
	if (args[1] == NULL)
	{
		update_status(0, 0, NULL);
		printf("\n");
		return ;
	}
	if (!ft_strncmp(args[1], "-n", 2))
		i = 1;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
	}
	if (ft_strncmp(args[1], "-n", 2))
		printf("\n");
	update_status(0, 0, NULL);
}

int	update_status(int new_val, int x, char *str)
{
	static int	exit_status;

	if (x != -10)
		exit_status = new_val % 255;
	if (x == 1 && str)
		printf("%s", str);
	return (exit_status);
}
