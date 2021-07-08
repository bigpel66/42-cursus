/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:30:37 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 11:36:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
