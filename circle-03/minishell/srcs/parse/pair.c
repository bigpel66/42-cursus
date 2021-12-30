/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:01 by jseo              #+#    #+#             */
/*   Updated: 2021/12/30 18:31:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// several functions by hyson
// rb_insert $
static void	insert_pid(t_rb *envmap)
{
	pid_t	pid;

	pid = getpid();
	rb_insert(envmap, jstrdup("$$"), jstrdup(jitoa((int)pid)));
}

// rb_insert #
static void	insert_argc(int argc, t_rb *envmap)
{
	--argc;
	rb_insert(envmap, jstrdup("$#"), jstrdup(jitoa(argc)));
}

// rb_insert *
static void insert_argv(int argc, char **argv, t_rb *envmap)
{
	char	*str;
	int 	i;

	i = 0;
	str = jstrjoin(argv[++i], " ");
	while (++i < argc)
	{
		str = jstrjoin(str, argv[i]);
		str = jstrjoin(str, " ");
	}
	rb_insert(envmap, jstrdup("$*"), jstrdup(str));
}
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
	insert_pid(envmap);
	insert_argc(argc, envmap);
	insert_argv(argc, argv, envmap);
	rb_insert(envmap, jstrdup("$_"), jstrdup("/usr/bin/env"));

	// rb_order(envmap->root);
}
