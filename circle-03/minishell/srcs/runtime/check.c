/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 14:58:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static inline bool	duplicated(char *cmd)
{
	bool	symbol[2];
	char	*search;

	symbol[0] = false;
	symbol[1] = false;
	search = NULL;
	while (*cmd)
	{
		if (*cmd == '\"')
			search = jstrchr(cmd + 1, '\"');
		if (search != NULL)
			cmd = search;
		if (*cmd == '\'')
			search = jstrchr(cmd + 1, '\'');
		if (search != NULL)
			cmd = search;
		if (*cmd == '|')
			symbol[0] = true;
		else if (*cmd == '<' || *cmd == '>')
			symbol[1] = true;
		if (symbol[0] && symbol[1])
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

// static inline int	get_priority(char current, char next)
// {
// 	if (current == '<' && next == '<')
// 		return (0);
// 	else if (current == '>' && next == '>')
// 		return (1);
// 	else if (current == '>')
// 		return (1);
// 	else if (current == '<')
// 		return (2);
// 	else
// 		return (-1);
// }

// static inline bool	redirection(char *cmd, int rdr)
// {
// 	int		priority;

// 	while (*cmd)
// 	{
// 		priority = get_priority(*cmd, *(cmd + 1));
// 		if (priority >= SUCCESS)
// 		{
// 			if (rdr & 0x1 || (rdr && rdr ^ (0x1 << priority)))
// 				return (false);
// 			rdr |= 0x1 << priority;
// 			if (priority / 2 == 0)
// 				++cmd;
// 		}
// 	}
// 	return (true);
// }

/*
** good ()				- Well Formed or Not
**
** return				- True or False
** cmd					- Input Command
*/

bool	good(char *cmd)
{
	return (quotes(cmd) && duplicated(cmd));
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
** 						- 0x2 (>>, >)
** 						- 0x4 (<)
*/

// |

// < < < <
// << <<
// > >> > >>

// static inline bool	clearness(char *cmd, bool pipe, int rdr)
// {
// 	int		i;
// 	int		priority;

// 	i = -1;
// 	while (cmd[++i])
// 	{

// 		if (cmd[i] == '|')
// 			pipe = true;
// 		priority = get_priority(cmd[i], cmd[i + 1]);
// 		if (priority != -1)
// 		{
// 			if (rdr & 0x1 || (rdr && rdr ^ (0x1 << priority)))
// 				return (false);
//
// 		}
// 		if (pipe && rdr)
// 			return (false);
// 	}
// 	return (true);
// }
