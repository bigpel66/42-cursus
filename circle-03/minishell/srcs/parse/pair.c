/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:01 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 03:09:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	// $$ $# $* PS1
	(void)argc, (void)argv;
	while (*envp)
	{
		value = jstrchr(*envp, '=');
		*value++ = '\0';
		rb_insert(envmap, jstrdup(*envp++), jstrdup(value));
	}
	// if no PS1, use "minishell$ "
	rb_insert(envmap, jstrdup("PS1"), jstrdup("minishell$ "));
	// rb_order(envmap->root);
}
