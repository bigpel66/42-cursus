/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 18:41:22 by jseo             ###   ########.fr       */
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
** clarity ()			- Check Clarity of Input Command
**
** return				- Input Command Well Formed or Not
** command				- Input Command
** pipe_exist			- Whether Pipe Exists or Not
** rdr_exist			- Whether Redirection Exists or Not
*/

bool	clarity(char *command)
{
	bool	pipe_exist;
	bool	rdr_exist;

	pipe_exist = false;
	rdr_exist = false;
	while (*command)
	{
		if (*command == '|')
			pipe_exist = true;
		if (*command == '<' || *command == '>')
			rdr_exist = true;
		if (*command == '\"')
			command = jstrchr(command + 1, '\"');
		if (command == NULL)
			return (false);
		if (*command == '\'')
			command = jstrchr(command + 1, '\'');
		if (command == NULL)
			return (false);
		++command;
	}
	return (!(pipe_exist && rdr_exist));
}
