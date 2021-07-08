/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 11:47:32 by jseo             ###   ########.fr       */
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
	int		i;

	i = -1;
	x->cnt = cnt - 2;
	if (!jcalloc((void **)(&(x->p)), x->cnt * 2, sizeof(int)))
		return (false);
	while (++i < x->cnt)
		if (pipe(x->p + i * 2) == ERROR)
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
	if (!path(envp, x))
		exit_invalid(x, true, "invalid envp\n", "");
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
