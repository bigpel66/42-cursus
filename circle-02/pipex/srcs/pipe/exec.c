/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:45:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/15 12:04:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_proc(t_arg *x, int i, pid_t pid)
{
	int		status;

	if (i == 0)
		close(x->a[WRITE]);
	else if (i == x->pipe && i % 2)
		close(x->b[WRITE]);
	else if (i == x->pipe && !(i % 2))
		close(x->a[WRITE]);
	else
	{
		if (i % 2)
		{
			close(x->a[READ]);
			close(x->b[WRITE]);
		}
		else
		{
			close(x->a[WRITE]);
			close(x->b[READ]);
		}
	}
	waitpid(pid, &status, 0);
}

static void	infile(char **envp, t_arg *x)
{
	t_fd	f;
	int		fd;

	close(x->a[READ]);
	if (x->heredoc)
	{
		fd = open(x->tmp, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == ERROR)
			exit_child(x, errno, NULL, NULL);
		none_fd(x, fd);
		fd = open(x->tmp, O_RDONLY);
		if (fd == ERROR)
			exit_child(x, errno, NULL, NULL);
		dup_fd(x, fd, STDIN_FILENO);
	}
	else
	{
		init_fd(&f, x->in, O_RDONLY, 0);
		get_fd(x, &f);
		dup_fd(x, f.fd, STDIN_FILENO);
	}
	dup_fd(x, x->a[WRITE], STDOUT_FILENO);
	call(envp, x, 0);
}

static void	outfile(char **envp, t_arg *x, bool odd)
{
	t_fd	f;
	int		flag;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (x->heredoc)
		flag = O_WRONLY | O_APPEND | O_CREAT;
	init_fd(&f, x->out, flag, 0644);
	get_fd(x, &f);
	if (odd)
	{
		close(x->a[WRITE]);
		dup_fd(x, x->a[READ], STDIN_FILENO);
	}
	else
	{
		close(x->b[WRITE]);
		dup_fd(x, x->b[READ], STDIN_FILENO);
	}
	dup_fd(x, f.fd, STDOUT_FILENO);
	call(envp, x, x->pipe);
}

static void	child_proc(char **envp, t_arg *x, int i)
{
	if (i == 0)
		infile(envp, x);
	else if (i == x->pipe)
		outfile(envp, x, i % 2);
	else
	{
		if (i % 2)
		{
			dup_fd(x, x->a[READ], STDIN_FILENO);
			dup_fd(x, x->b[WRITE], STDOUT_FILENO);
		}
		else
		{
			dup_fd(x, x->b[READ], STDIN_FILENO);
			dup_fd(x, x->a[WRITE], STDOUT_FILENO);
		}
		call(envp, x, i);
	}
	exit_valid(x);
}

void	exec(char **envp, t_arg *x)
{
	int		i;
	int		*p;
	pid_t	pid;

	i = -1;
	while (++i < x->pipe + 1)
	{
		p = x->a;
		if (i % 2)
			p = x->b;
		if (pipe(p) == ERROR)
			exit_invalid(x, false, NULL, NULL);
		pid = fork();
		if (pid == ERROR)
			exit_invalid(x, false, NULL, NULL);
		else if (!pid)
			child_proc(envp, x, i);
		else
			parent_proc(x, i, pid);
	}
}
