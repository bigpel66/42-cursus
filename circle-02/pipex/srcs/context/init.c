/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/12 19:31:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	prepare(t_arg *x, int cnt)
{
	int		i;

	i = -1;
	x->pipe = cnt - 2;
	if (!jcalloc((void **)(&(x->file)), cnt, sizeof(char *)))
		return (false);
	if (!jcalloc((void **)(&(x->vec)), cnt, sizeof(char **)))
		return (false);
	return (true);
}

static bool	check(char **argv, t_arg *x)
{
	x->in = argv[1];
	if (access(x->in, F_OK) == ERROR)
		return (false);
	return (true);
}

void	init(int argc, char **argv, char **envp, t_arg *x)
{
	int		i;

	i = 1;
	x->out = argv[argc - 1];
	if (!path(envp, x))
		exit_invalid(x, true, "invalid envp", "");
	if (!prepare(x, argc - 2))
		exit_invalid(x, false, "", "");
	if (!(x->heredoc))
		if (!check(argv, x))
			exit_invalid(x, true, "no such file or directory: ", x->in);
	while (++i < argc - 1)
		if (!command(x, argv[i], i - 2))
			exit_invalid(x, false, "", "");
}
