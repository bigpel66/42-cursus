/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:48 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 12:49:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** quotes ()			- Check Quotes Well Formed or Not
**
** return				- True or False
** str					- String to Check Quotes
*/

static inline bool	quotes(char *str)
{
	while (*str)
	{
		if (*str == '\"')
			str = jstrchr(str + 1, '\"');
		if (str == NULL)
			return (false);
		if (*str == '\'')
			str = jstrchr(str + 1, '\'');
		if (str == NULL)
			return (false);
		++str;
	}
	return (true);
}

/*
** execute ()			- Initiate and Execute from AS Tree
**
** return				- void
** chunks				- Variable for Tokens of User Input
** syntax				- Variable for a Syntax Tree from Chunks
** envmap				- Variable for Maps the Environment Variables
*/

static inline void	execute(t_lst *chunks, t_as *syntax, t_rb *envmap)
{
	syntax = as_init(chunks);
	// as_print(syntax);
	as_exec(syntax, envmap);
	as_free(syntax);
}

/*
** loop ()				- Main Runtime Function of Minishell
**
** return				- void
** input				- Variable for a User Input
** chunks				- Variable for Tokens of User Input
** syntax				- Variable for a Syntax Tree from Chunks
** envmap				- Variable for Maps the Environment Variables
*/

void	loop(char *input, t_lst *chunks, t_as *syntax, t_rb *envmap)
{
	while (true)
	{
		jfree((void **)(&input));
		input = readline(get_value(envmap, "PS1"));
		if (input == NULL)
		{
			jputendl("exit", STDOUT_FILENO);
			exit(VALID);
		}
		if (!jstrlen(input))
			continue ;
		add_history(input);
		if (!quotes(input) && set_rl("Quotes not paired", STDERR_FILENO))
			continue ;
		input = expand(input, envmap, false);
		mini_assert(input != NULL, \
			MASSERT "(input != NULL), " LOOP MLOOP_FILE "line 83.");
		tokenize(input, &chunks);
		mini_assert(chunks != NULL, \
			MASSERT "(chunks != NULL), " LOOP MLOOP_FILE "line 86.");
		echoctl_on();
		execute(chunks, syntax, envmap);
		jlstclear(&chunks, jfree);
		echoctl_off();
	}
}

/*
** finish ()			- Finish the Loop
**
** return				- void
** entry				- Print the Error Entry If Error Exists
** shutdown				- Just Return or Exit
*/

void	finish(char *entry, bool shutdown)
{
	if (errno)
		jputstr(entry, STDERR_FILENO);
	if (errno == ENOENT)
	{
		jputendl(": No such file or directory", STDERR_FILENO);
		if (shutdown)
			exit(GENERAL);
	}
	if (errno == EFAULT)
	{
		jputendl(": Command not found", STDERR_FILENO);
		if (shutdown)
			exit(NOTFOUND);
	}
	if (errno == EACCES)
	{
		jputendl(": Permission denied", STDERR_FILENO);
		if (shutdown)
			exit(NOTEXECUTABLE);
	}
	if (shutdown)
		exit(VALID);
}
