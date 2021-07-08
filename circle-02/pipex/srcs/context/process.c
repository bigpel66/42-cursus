/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:34:51 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 17:53:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	quote(int c)
{
	return (c == '\'');
}

bool	delimiter(int c)
{
	return (c == ':');
}

bool	command(t_arg *x, const char *cmd, int i)
{
	int		j;
	bool	mode;

	j = -1;
	mode = false;
	while (cmd[++j])
		if (quote(cmd[j]))
			mode = true;
	if (mode)
		x->vec[i] = jargs(cmd);
	else
		x->vec[i] = jsplit(cmd, jisspace);
	if (!(x->vec[i]))
		return (false);
	return (true);
}

void	block(t_arg *x, pid_t pid)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		if (WEXITSTATUS(status) == INVALID)
			exit_invalid(x, true, "", "");
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
