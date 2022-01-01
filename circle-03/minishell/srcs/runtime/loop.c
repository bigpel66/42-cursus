/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:48 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 02:08:50 by jseo             ###   ########.fr       */
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
		input = readline("hi$ ");
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
			MASSERT "(input != NULL), " LOOP MLOOP_FILE "line 66.");
		tokenize(input, &chunks);
		mini_assert(chunks != NULL, \
			MASSERT "(chunks != NULL), " LOOP MLOOP_FILE "line 69.");
		// jlstshow(chunks);
		syntax = as_init(chunks);
		// as_print(syntax);
		as_exec(syntax, envmap);
		as_free(syntax);
		jlstclear(&chunks, jfree);
	}
}
