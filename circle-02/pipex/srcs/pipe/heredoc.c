/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:03:52 by jseo              #+#    #+#             */
/*   Updated: 2021/07/14 23:07:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(t_arg *x)
{
	int		p[2];
	pid_t	pid;

	if (pipe(p) == ERROR)
		exit_child(x, errno, NULL, NULL);
	pid = fork();
	if (pid == ERROR)
		exit_child(x, errno, NULL, NULL);
	else if (!pid)
	{
		none_fd(x, p);
		exit_valid(x);
	}
	else
	{
		close(p[WRITE]);
		dup_fd(x, p[READ], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
