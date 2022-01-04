/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 15:04:27 by jseo             ###   ########.fr       */
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

/*
** duplicated ()		- Pipe and Redirection Duplicated or Not
**
** return				- True or False
** cmd					- Input Command
** symbol				- [0]: pipe, [1]: redirection
** search				- Search for the Next Quote
*/

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
** good ()				- Well Formed or Not
**
** return				- True or False
** cmd					- Input Command
*/

bool	good(char *cmd)
{
	return (quotes(cmd) && duplicated(cmd));
}
