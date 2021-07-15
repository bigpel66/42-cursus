/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:45:08 by jseo              #+#    #+#             */
/*   Updated: 2021/07/15 11:52:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd(t_fd *f, char *file, int flag, int mode)
{
	f->file = file;
	f->flag = flag;
	f->mode = mode;
}

void	none_fd(t_arg *x, int fd)
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
			exit_child(x, errno, NULL, NULL);
		ret = (int)jstrlen(line);
		if (ret < (int)jstrlen(x->limiter))
			ret = (int)jstrlen(x->limiter);
		ret = jstrncmp(line, x->limiter, (size_t)ret);
		if (ret)
			jputendl(line, fd);
		jfree((void **)(&line));
		if (!ret)
			break ;
	}
	close(fd);
}

void	get_fd(t_arg *x, t_fd *f)
{
	if (f->mode)
		f->fd = open(f->file, f->flag, f->mode);
	else
		f->fd = open(f->file, f->flag);
	if (f->fd == ERROR)
		exit_child(x, END, "no such file or directory: ", f->file);
}

void	dup_fd(t_arg *x, int dst, int src)
{
	int		fd;

	fd = dup2(dst, src);
	close(dst);
	if (fd == ERROR)
		exit_child(x, errno, NULL, NULL);
}

void	call(char **envp, t_arg *x, int i)
{
	if (access(x->file[i], F_OK) == ERROR)
	{
		if (!jstrchr(x->file[i], '/'))
			exit_child(x, END, "command not found: ", x->file[i]);
		else
			exit_child(x, END, "no such file or directory: ", x->file[i]);
	}
	else if (access(x->file[i], X_OK) == ERROR
		|| x->file[i][jstrlen(x->file[i]) - 1] == '/')
		exit_child(x, END, "permission denied: ", x->file[i]);
	else if (execve(x->file[i], x->vec[i], envp) == ERROR)
		exit_child(x, END, NULL, NULL);
}
