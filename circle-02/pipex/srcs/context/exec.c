/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:27:10 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 11:47:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	infile(char **envp, t_arg *x)
{
	t_fd	f;

	close(x->p[0]);
	init_fd(&f, x->in, O_RDONLY, 0);
	if (x->heredoc)
		none_fd(x);
	else
	{
		get_fd(x, &f);
		dup_fd(x, f.fd, STDIN_FILENO);
	}
	dup_fd(x, x->p[1], STDOUT_FILENO);
	process(envp, x, 0);
}

// static void	commands(char **envp, t_arg *x)
// {
	// int		i;
	// int		p[2];
	// pid_t	pid;

	// i = 0;
	// while (++i < x->cnt - 1)
	// {
	// 	printf("hi\n");
	// 	pid = fork();
	// 	if (pid == ERROR)
	// 		exit_invalid(x, false, "", "");
	// 	else if (pid == CHILD)
	// 	{
	// 		dup_fd(x, x->p[P_READ], STDIN_FILENO);
	// 		dup_fd(x, x->p[P_WRITE], STDOUT_FILENO);
	// 		process(envp, x, i);
	// 	}
	// 	else
	// 		block(x, pid);
	// }
// }

static void	outfile(char **envp, t_arg *x, pid_t pid)
{
	t_fd	f;
	int		flag;

	flag = O_WRONLY | O_CREAT;
	if (x->heredoc)
		flag |= O_APPEND;
	close(x->p[x->cnt * 2 - 1]);
	init_fd(&f, x->out, flag, 0755);
	get_fd(x, &f);
	dup_fd(x, x->p[x->cnt * 2 - 2], STDIN_FILENO);
	dup_fd(x, f.fd, STDOUT_FILENO);
	process(envp, x, x->cnt);
}

void	exec(char **envp, t_arg *x)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		exit_invalid(x, false, "", "");
	else if (pid == CHILD)
		infile(envp, x);
	else
	{
		block(x, pid);
		// commands(envp, x);
		outfile(envp, x, pid);
	}
}
