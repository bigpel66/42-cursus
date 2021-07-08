/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 01:27:22 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 19:19:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd(t_fd *f, char *file, int flag, int mode)
{
	f->file = file;
	f->flag = flag;
	f->mode = mode;
}

void	none_fd(t_arg *x)
{
	int		ret;
	char	*line;

	while (true)
	{
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		ret = jgnl(STDIN_FILENO, &line);
		if (ret == ERROR)
			exit_invalid(x, false, "", "");
		ret = jstrncmp(line, x->limiter, jstrlen(x->limiter));
		if (ret)
		{
			write(x->fd, line, jstrlen(line));
			write(x->fd, "\n", 1);
		}
		jfree((void **)(&line));
		if (!ret)
			break ;
	}
	close(x->fd);
}

void	get_fd(t_arg *x, t_fd *f)
{
	if (f->mode)
		f->fd = open(f->file, f->flag, f->mode);
	else
		f->fd = open(f->file, f->flag);
	if (f->fd == ERROR)
		exit_invalid(x, true, "permission denied: ", f->file);
}

void	dup_fd(t_arg *x, int dst, int src)
{
	int		fd;

	fd = dup2(dst, src);
	close(dst);
	if (fd == ERROR)
		exit_invalid(x, false, "", "");
}
