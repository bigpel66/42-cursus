/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:34:51 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 14:51:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_infile(char **argv, t_arg *x)
{
	x->in = argv[1];
	if (access(x->in, F_OK) == ERROR)
		return (false);
	return (true);
}

bool	parse_command(t_arg *x, const char *cmd, int i)
{
	int		j;
	char	*corr;
	char	*file;

	x->vec[i] = jsplit(cmd, jisspace);
	if (!(x->vec[i]))
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

void	process(char **envp, t_arg *x, int i)
{
	if (execve(x->file[i], x->vec[i], envp) == ERROR)
	{
		if (errno == EACCES)
			exit_invalid(x, true, "permission denied: ", x->file[i]);
		else
			exit_invalid(x, true, "command not found: ", x->file[i]);
	}
}

void	block(t_arg *x, pid_t pid)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		if (WEXITSTATUS(status) == INVALID)
			exit_invalid(x, true, "", "");
}
