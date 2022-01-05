/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/05 09:04:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** mini_assert ()		- Assert Whether Condition True or False
**
** return				- void
** condition			- Condition to Check
** context				- Context Information in Runtime
*/

void	mini_assert(bool condition, char *context)
{
	if (condition)
		return ;
	jputendl(context, STDERR_FILENO);
	exit(GENERAL);
}

/*
** empty ()				- Check the Input Empty or Not
**
** return				- True or False
** input				- Variable for a User Input
*/

bool	empty(char *input)
{
	int		i;

	i = -1;
	while (input[++i])
		if (!jisspace(input[i]))
			return (false);
	return (true);
}

/*
** quotes ()			- Check Quotes
**
** return				- True or False
** cmd					- Input Command
*/

bool	quotes(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '\"')
			cmd = jstrchr(cmd + 1, '\"');
		if (cmd == NULL)
			return (false);
		if (*cmd == '\'')
			cmd = jstrchr(cmd + 1, '\'');
		if (cmd == NULL)
			return (false);
		++cmd;
	}
	return (true);
}
