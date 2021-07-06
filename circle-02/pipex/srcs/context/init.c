/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 00:51:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	prepare(t_arg *x, int cnt)
{
	if (pipe(x->p) == ERROR)
		return (false);
	if (!jcalloc((void **)(&(x->file)), cnt, sizeof(char *)))
		return (false);
	if (!jcalloc((void **)(&(x->vec)), cnt, sizeof(char **)))
		return (false);
	return (true);
}

static bool	delimiter(int c)
{
	return (c == ':');
}

void	init(int argc, char **argv, t_arg *x)
{
	int		i;

	i = 1;
	if (!prepare(x, argc - 2))
		exit_invalid(x, false, "", "");
	if (x->heredoc)
		if (!parse_stdin(x))
			exit_invalid(x, false, "", "");
	if (!(x->heredoc))
		if (!check_infile(x))
			exit_invalid(x, true, "no such file or directory: ", x->in);
	while (++i < argc - 1)
	{
		if (!parse_command(x, argv[i], i - 2))
			exit_invalid(x, false, "", "");
		if (!check_command(x, i - 2))
			exit_invalid(x, true, "command not found: ", x->vec[i - 2][0]);
	}
	x->out = argv[i];
}

bool	path(char **envp, t_arg *x)
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
