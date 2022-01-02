/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 19:45:39 by jseo             ###   ########.fr       */
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
** quotes ()			- Check Quotes
**
** return				- True or False
** cmd					- Input Command
*/

static inline bool	quotes(char *cmd)
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

/*
** clearness ()			- Check Clearness
**
** return				- True or False
** cmd					- Input Command
** pipe					- Whether Pipe Exists
** rdr					- Whether Redirection Exists
** i					- Index to Iterate All Elements
*/

static inline bool	clearness(char *cmd, bool pipe, bool rdr)
{
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '|')
			pipe = true;
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			if (rdr)
				return (false);
			rdr = true;
			if (cmd[i] == cmd[i + 1])
				++i;
		}
		if (pipe && rdr)
			return (false);
	}
	return (true);
}

/*
** good ()				- Well Formed or Not
**
** return				- True or False
** cmd					- Input Command
*/

bool	good(char *cmd)
{
	return (quotes(cmd) && clearness(cmd, false, false));
}
