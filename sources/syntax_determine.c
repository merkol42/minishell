/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_determine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:42:09 by ftuncer           #+#    #+#             */
/*   Updated: 2022/09/26 11:15:54 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_shell.h"

int	determine_syntax(char *str, int i)
{
	if (str[i] == '<')
	{
		if (!check_right_r(i, str))
			return (update_status(258 * 256, 1,
					"syntax error near unexpected token '<'\n"));
	}
	else if (str[i] == '>')
	{
		if (!check_right(i, str))
			return (update_status(258 * 256, 1,
					"syntax error near unexpected token '>'\n"));
	}
	return (0);
}
