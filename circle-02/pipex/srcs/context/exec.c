/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:24:09 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 14:52:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_proc(t_arg *x, int i, pid_t pid)
{
	if (i == 0)
		close(x->a[1]);
	else if (i == x->pipe && i % 2)
		close(x->b[1]);
	else if (i == x->pipe && !(i % 2))
		close(x->a[1]);
	else
	{
		if (i % 2)
		{
			close(x->a[0]);
			close(x->b[1]);
		}
		else
		{
			close(x->a[1]);
			close(x->b[0]);
		}
	}
	block(x, pid);
}

static void	infile(char **envp, t_arg *x)
{
	t_fd	f;

	close(x->a[0]);
	init_fd(&f, x->in, O_RDONLY, 0);
	if (x->heredoc)
		none_fd(x);
	else
	{
		get_fd(x, &f);
		dup_fd(x, f.fd, STDIN_FILENO);
	}
	dup_fd(x, x->a[1], STDOUT_FILENO);
	process(envp, x, 0);
}

static void	outfile(char **envp, t_arg *x, bool odd)
{
	t_fd	f;
	int		flag;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (x->heredoc)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	init_fd(&f, x->out, flag, 0755);
	get_fd(x, &f);
	if (odd)
	{
		close(x->a[1]);
		dup_fd(x, x->a[0], STDIN_FILENO);
	}
	else
	{
		close(x->b[1]);
		dup_fd(x, x->b[0], STDIN_FILENO);
	}
	dup_fd(x, f.fd, STDOUT_FILENO);
	process(envp, x, x->pipe);
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
			dup_fd(x, x->a[0], STDIN_FILENO);
			dup_fd(x, x->b[1], STDOUT_FILENO);
		}
		else
		{
			dup_fd(x, x->b[0], STDIN_FILENO);
			dup_fd(x, x->a[1], STDOUT_FILENO);
		}
		process(envp, x, i);
	}
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
			exit_invalid(x, false, "", "");
		pid = fork();
		if (pid == ERROR)
			exit_invalid(x, false, "", "");
		else if (pid == CHILD)
			child_proc(envp, x, i);
		else
			parent_proc(x, i, pid);
	}
}
