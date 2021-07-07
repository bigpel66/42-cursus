/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:27:10 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 16:57:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(t_arg *x, char **envp)
{
	int	fd;

	fd = open(x->in, O_RDONLY);
	if (fd == ERROR)
		exit_invalid(x, true, "permission denied: ", x->in);
	if (dup2(fd, STDIN_FILENO) == ERROR)
		exit_invalid(x, false, "", "");
	close(x->p[P_READ]);
	if (dup2(x->p[P_WRITE], STDOUT_FILENO) == ERROR)
		exit_invalid(x, false, "", "");
	close(x->p[P_WRITE]);
	if (execve(x->file[0], x->vec[0], envp) == ERROR)
	{
		//something
	}
}

void	parent_proc(t_arg *x, pid_t pid, char **envp)
{
	int	status;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		if (WEXITSTATUS(status) == INVALID)
			exit_invalid(x, true, "", "");
	// parent things;
}

void	exec(t_arg *x, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		exit_invalid(x, false, "", "");
	else if (pid == CHILD)
		child_proc(x, envp);
	else
		parent_proc(x, pid, envp);
	return ;
}
