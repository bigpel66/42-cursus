/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/03 14:43:53 by jseo             ###   ########.fr       */
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
** get_priority ()		- Get Priority Value on Redirection Symbol
**
** return				- Priority (0 - <<, 1 - >>, 2 - <, 3 - >, else -1)
** current				- Current Character
** next					- Next Character
*/

static inline int	get_priority(char current, char next)
{
	if (current == '<' && next == '<')
		return (0);
	else if (current == '>' && next == '>')
		return (1);
	else if (current == '<')
		return (2);
	else if (current == '>')
		return (3);
	else
		return (-1);
}

/*
** clearness ()			- Check Clearness
**
** return				- True or False
** cmd					- Input Command
** pipe					- Whether Pipe Exists
** rdr					- Whether Redirection Exists
** i					- Index to Iterate All Elements
** priority				- Priority of Redirection Symbol
** rdr bit type			- 0x0 (None)
** 						- 0x1 (<<)
** 						- 0x2 (>>)
** 						- 0x4 (<)
** 						- 0x8 (>)
*/

static inline bool	clearness(char *cmd, bool pipe, int rdr)
{
	int		i;
	int		priority;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '|')
			pipe = true;
		priority = get_priority(cmd[i], cmd[i + 1]);
		if (priority != -1)
		{
			if (rdr & 0x1 || (rdr && rdr ^ (0x1 << priority)))
				return (false);
			rdr |= 0x1 << priority;
			if (priority / 2 == 0)
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
	return (quotes(cmd) && clearness(cmd, false, 0));
}
