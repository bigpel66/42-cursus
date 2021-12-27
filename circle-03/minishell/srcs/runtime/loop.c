/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:02:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/27 12:52:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	(void)syntax;
	while (true)
	{
		jfree((void **)(&input));
		input = readline("hi$ ");
		mini_assert(input != NULL, \
			MASSERT "(input != NULL), " LOOP MLOOP_FILE "line 32.");
		if (!jstrlen(input))
			continue ;
		add_history(input);
		input = expand(input, envmap, false);
		printf("input : %s\n\n", input);
		mini_assert(input != NULL, \
			MASSERT "(input != NULL), " LOOP MLOOP_FILE "line 39.");
		tokenize(input, &chunks);
		mini_assert(chunks != NULL, \
			MASSERT "(chunks != NULL), " LOOP MLOOP_FILE "line 42.");
		jlstshow(chunks);
		// syntax = as_init(chunks);
		// as_exec(syntax, envmap);
		// as_free(syntax);
		jlstclear(&chunks, jfree);
	}
}
