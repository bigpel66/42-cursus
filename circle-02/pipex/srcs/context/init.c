/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/14 23:02:11 by jseo             ###   ########.fr       */
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
	x->in = argv[i];
	if (!path(envp, x))
		exit_invalid(x, true, "invalid envp", NULL);
	if (!prepare(x, argc - 2))
		exit_invalid(x, false, NULL, NULL);
	while (++i < argc - 1)
		if (!command(x, argv[i], i - 2))
			exit_invalid(x, false, NULL, NULL);
}
