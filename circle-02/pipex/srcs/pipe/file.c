/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:45:08 by jseo              #+#    #+#             */
/*   Updated: 2021/07/12 19:20:34 by jseo             ###   ########.fr       */
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
	int		i;
	int		ret;
	char	*line;

	while (true)
	{
		i = -1;
		while (++i < x->pipe)
			jputstr("pipe ", STDOUT_FILENO);
		jputstr("heredoc> ", STDOUT_FILENO);
		ret = jgnl(STDIN_FILENO, &line);
		if (ret == ERROR)
			exit_child(x, errno);
		ret = jstrncmp(line, x->limiter, jstrlen(x->limiter));
		if (ret)
			jputendl(line, x->fd);
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
		exit_child(x, errno);
}

void	dup_fd(t_arg *x, int dst, int src)
{
	int		fd;

	fd = dup2(dst, src);
	close(dst);
	if (fd == ERROR)
		exit_child(x, errno);
}

void	call(char **envp, t_arg *x, int i)
{
	if (!jstrchr(x->file[i], '/') || access(x->file[i], F_OK) == ERROR)
		exit_child(x, ENOENT);
	if (access(x->file[i], X_OK) == ERROR)
		exit_child(x, EACCES);
	if (execve(x->file[i], x->vec[i], envp) == ERROR)
		exit_child(x, errno);
}
