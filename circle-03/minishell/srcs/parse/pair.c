/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:01 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:39:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** pair_argc ()			- Pair Argc into the Envmap
**
** return				- void
** argc					- The Number of Argument
** envmap				- Variable for Maps the Environment Variables
*/

static inline void	pair_argc(int argc, t_rb *envmap)
{
	rb_insert(envmap, jstrdup("#"), jstrdup(jitoa(argc - 1)));
}

/*
** pair_argv ()			- Pair Argv into the Envmap
**
** return				- void
** argc					- The Number of Argument
** argv					- The Actual Arguments
** envmap				- Variable for Maps the Environment Variables
** i					- Index to Use
** str					- String to Use
** temp					- Temp String to Use
*/

static inline void	pair_argv(int argc, char **argv, t_rb *envmap)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	temp = jstrdup("");
	while (++i < argc)
	{
		str = jstrjoin(temp, argv[i]);
		jfree((void **)(&temp));
		temp = str;
		if (i == argc - 1)
			break ;
		str = jstrjoin(temp, " ");
		jfree((void **)(&temp));
		temp = str;
	}
	if (argc == 1)
		str = temp;
	mini_assert(str != NULL, \
		MASSERT "(str != NULL), " PAIR_ARGV MPAIR_FILE "line 41.");
	rb_insert(envmap, jstrdup("*"), str);
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

	while (*envp != NULL)
	{
		value = jstrchr(*envp, '=');
		*value++ = '\0';
		rb_insert(envmap, jstrdup(*envp++), jstrdup(value));
	}
	rb_insert(envmap, jstrdup("PS1"), jstrdup("minishell$ "));
	rb_insert(envmap, jstrdup("?"), jstrdup(jitoa(0)));
	pair_argc(argc, envmap);
	pair_argv(argc, argv, envmap);
}
