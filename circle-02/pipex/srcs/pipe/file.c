/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:45:08 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 18:29:26 by jseo             ###   ########.fr       */
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
		jputstr("heredoc>", STDOUT_FILENO);
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
	if (execve(x->file[i], x->vec[i], envp) == ERROR)
	{
		if (errno == EACCES)
			exit_child(x, PERMISSION);
		else if (errno == ENOENT)
			exit_child(x, COMMAND);
		else
			exit_child(x, errno);
	}
}
