/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:01 by jseo              #+#    #+#             */
/*   Updated: 2021/12/30 16:44:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// several functions by hyson

/*
** pair ()				- Pair the Entire Environment Variables
**
** return				- void
** argc					- The Number of Argument
** argv					- The Actual Arguments
** envp					- The Environment Variables on the Entry Time
** envmap				- Variable for Maps the Environment Variables
** value				- Value from the Specific Key on the Envmap
*/

void	pair(int argc, char **argv, char **envp, t_rb *envmap)
{
	char	*value;

	// $$ $# $* PS1 _ signal
	(void)argc, (void)argv;
	while (*envp != NULL)
	{
		value = jstrchr(*envp, '=');
		*value++ = '\0';
		rb_insert(envmap, jstrdup(*envp++), jstrdup(value));
	}
	// if no PS1, use "minishell$ "
	rb_insert(envmap, jstrdup("PS1"), jstrdup("minishell$ "));
	// rb_insert $
	// rb_insert #
	// rb_insert *
	// rb_insert _

	// rb_order(envmap->root);
}
