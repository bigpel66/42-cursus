/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/12 20:57:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_child(t_arg *x, int code)
{
	free_arg(x);
	exit(code);
}

static void	branch_enoent(t_arg *x, int code, int i)
{
	int		ret;
	char	*chk;
	char	*tmp;

	if (!jstrchr(x->file[i], '/'))
		exit_invalid(x, true, "command not found: ", x->file[i]);
	if ((x->file[i][0] == '.' || x->file[i][0] == '/'))
		exit_invalid(x, true, "no such file or directory: ", x->file[i]);
	chk = jstrdup(x->file[i]);
	if (chk)
	{
		tmp = jstrchr(chk, '/');
		if (tmp)
			*tmp = '\0';
		ret = access(chk, F_OK);
		jfree((void **)(&chk));
		if (!ret)
			exit_invalid(x, true, "not a directory: ", x->file[i]);
		exit_invalid(x, true, "no such file or directory: ", x->file[i]);
	}
}

void	exit_parent(t_arg *x, int code, int i)
{
	if (code == EACCES)
		exit_invalid(x, true, "permission denied: ", x->file[i]);
	else if (code == ENOENT)
	{
		if (x->file[i][0] == '/' && !access(x->file[i], F_OK))
			return ;
		branch_enoent(x, code, i);
	}
	errno = code;
	exit_invalid(x, false, "", "");
}

void	exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2)
{
	int		fd;

	if (x && x->out && access(x->out, F_OK) == ERROR)
		fd = open(x->out, O_CREAT | O_WRONLY, 0644);
	if (fd != ERROR)
		close(fd);
	if (custom)
	{
		jputstr((char *)s1, STDERR_FILENO);
		jputstr((char *)s2, STDERR_FILENO);
		if (*s1)
			jputchar('\n', STDERR_FILENO);
	}
	else
		strerror(errno);
	free_arg(x);
	exit(INVALID);
}

void	exit_valid(t_arg *x)
{
	free_arg(x);
	exit(VALID);
}
