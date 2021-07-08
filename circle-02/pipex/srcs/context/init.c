/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 10:06:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	delimiter(int c)
{
	return (c == ':');
}

static bool	path(char **envp, t_arg *x)
{
	char	*path;

	while (*envp && jstrncmp(*envp, "PATH", 4))
		++envp;
	if (!(*envp))
		return (false);
	path = *envp;
	x->path = jsplit(path + 5, delimiter);
	if (!(x->path))
		return (false);
	return (true);
}

static bool	prepare(t_arg *x, int cnt)
{
	x->cnt = cnt - 1;
	if (pipe(x->p) == ERROR)
		return (false);
	if (!jcalloc((void **)(&(x->file)), cnt, sizeof(char *)))
		return (false);
	if (!jcalloc((void **)(&(x->vec)), cnt, sizeof(char **)))
		return (false);
	return (true);
}

void	init(int argc, char **argv, char **envp, t_arg *x)
{
	int		i;

	i = 1;
	if (!path(envp, &x))
		exit_invalid(&x, true, "invalid envp\n", "");
	if (!prepare(x, argc - 2))
		exit_invalid(x, false, "", "");
	if (!(x->heredoc))
		if (!check_infile(argv, x))
			exit_invalid(x, true, "no such file or directory: ", x->in);
	while (++i < argc - 1)
		if (!parse_command(x, argv[i], i - 2))
			exit_invalid(x, false, "", "");
	x->out = argv[i];
}
