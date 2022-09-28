/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:53:12 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/23 12:10:07 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

static int	charcnt2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '<' && s[i] != '>'))
		i++;
	return (i);
}

static int	word2(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		while ((*s == '<' || *s == '>') && *s)
			s++;
		if (*s == '\0')
			return (i);
		while ((*s != '<' && *s != '>') && *s)
			s++;
		i++;
	}
	return (i);
}

char	**ft_split_cmds(char const *s)
{
	char	**spl;
	int		splidx;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = -1;
	splidx = 0;
	spl = malloc(sizeof(char *) * word2(s) + 1);
	if (!spl)
		return (0);
	while (++j < word2(s))
	{
		while ((s[i] == '<' || s[i] == '>') && s[i])
			i++;
		ret = ft_substr(&s[i], 0, charcnt2(&s[i]));
		spl[splidx] = ft_strtrim(ret, " ");
		free(ret);
		splidx++;
		while ((s[i] != '<' && s[i] != '>') && s[i])
			i++;
	}
	spl[splidx] = NULL;
	return (spl);
}

int	red_count(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '<' || str[i] == '>'))
			i++;
		if (str[i])
			ret++;
		while (str[i] && (str[i] != '<' && str[i] != '>'))
			i++;
	}
	return (ret);
}

char	**make_redir(char **redirs, char const *s)
{
	int		i;
	int		j;
	int		idx;
	char	*ret;

	i = 0;
	j = 0;
	idx = -1;
	while (s[i])
	{
		while (s[i] && (s[i] != '<' && s[i] != '>'))
			i++;
		j = i;
		while (s[j] && (s[j] == '<' || s[j] == '>'))
			j++;
		if (s[j] && s[j] != '<' && s[j] != '>')
		{
			ret = ft_substr(s, i, j - i);
			redirs[++idx] = ft_strtrim(ret, " ");
			free(ret);
		}
		i = j;
	}
	redirs[++idx] = NULL;
	return (redirs);
}
