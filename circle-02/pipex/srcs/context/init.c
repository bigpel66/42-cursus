/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 17:31:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	x->pipe = cnt - 2;
	if (!jcalloc((void **)(&(x->file)), cnt, sizeof(char *)))
		return (false);
	if (!jcalloc((void **)(&(x->vec)), cnt, sizeof(char **)))
		return (false);
	return (true);
}

static bool	check_infile(char **argv, t_arg *x)
{
	x->in = argv[1];
	if (access(x->in, F_OK) == ERROR)
		return (false);
	return (true);
}

static bool	parse_command(t_arg *x, const char *cmd, int i)
{
	int		j;
	char	*corr;
	char	*file;

	if (!command(x, cmd, i))
		return (false);
	j = -1;
	while (x->path[++j])
	{
		corr = jstrjoin(x->path[j], "/");
		file = jstrjoin(corr, x->vec[i][0]);
		jfree((void **)(&corr));
		if (!access(file, F_OK))
		{
			x->file[i] = file;
			return (true);
		}
		jfree((void **)(&file));
	}
	x->file[i] = jstrdup(x->vec[i][0]);
	if (!(x->file[i]))
		return (false);
	return (true);
}

void	init(int argc, char **argv, char **envp, t_arg *x)
{
	int		i;

	i = 1;
	if (!path(envp, x))
		exit_invalid(x, true, "invalid envp", "");
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
