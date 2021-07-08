/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:27:10 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 10:11:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process(char **envp, t_arg *x, int i)
{
	if (execve(x->file[i], x->vec[i], envp) == ERROR)
	{
		if (errno == EACCES)
			exit_invalid(x, true, "permission denied: ", x->file[i]);
		else
			exit_invalid(x, true, "command not found: ", x->file[i]);
	}
}

static void	in_proc(t_arg *x, pid_t pid, char **envp)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		if (WEXITSTATUS(status) == INVALID)
			exit_invalid(x, true, "", "");
}

static void	child_proc(char **envp, t_arg *x)
{
	t_fd	f;

	close(x->p[P_READ]);
	init_fd(&f, x->in, O_RDONLY, 0);
	if (x->heredoc)
		none_fd(x);
	else
	{
		get_fd(x, &f);
		dup_fd(x, f.fd, STDIN_FILENO);
	}
	dup_fd(x, x->p[P_WRITE], STDOUT_FILENO);
	process(envp, x, 0);
}

static void	parent_proc(char **envp, t_arg *x, pid_t pid)
{
	t_fd	f;
	int		flag;

	flag = O_WRONLY | O_CREAT;
	if (x->heredoc)
		flag |= O_APPEND;
	in_proc(x, pid, envp);
	close(x->p[P_WRITE]);
	init_fd(&f, x->out, flag, 0755);
	get_fd(x, &f);
	dup_fd(x, x->p[P_READ], STDIN_FILENO);
	dup_fd(x, f.fd, STDOUT_FILENO);
	process(envp, x, x->cnt - 1);
}

void	exec(char **envp, t_arg *x)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		exit_invalid(x, false, "", "");
	else if (pid == CHILD)
		child_proc(envp, x);
	else
		parent_proc(envp, x, pid);
	return ;
}
