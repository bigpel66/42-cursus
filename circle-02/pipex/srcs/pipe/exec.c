/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:19:00 by jseo              #+#    #+#             */
/*   Updated: 2021/07/14 23:31:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	enoent(t_arg *x, int i)
{
	int		ret;
	char	*chk;
	char	*tmp;

	if (!jstrchr(x->file[i], '/'))
		exit_child(x, END, "command not found: ", x->file[i]);
	else if (x->file[i][0] == '.' || x->file[i][0] == '/')
		exit_child(x, END, "no such file or directory: ", x->file[i]);
	chk = jstrdup(x->file[i]);
	if (chk)
	{
		tmp = jstrchr(chk, '/');
		if (tmp)
			*tmp = '\0';
		ret = access(chk, F_OK);
		jfree((void **)(&chk));
		if (!ret)
			exit_child(x, END, "not a directory: ", x->file[i]);
		exit_child(x, END, "no such file or directory: ", x->file[i]);
	}
	exit_child(x, errno, NULL, NULL);
}

void	exec(char **envp, t_arg *x, int i)
{
	if (access(x->file[i], F_OK) == ERROR)
		enoent(x, i);
	else if (access(x->file[i], X_OK) == ERROR)
		exit_child(x, END, "permission denied: ", x->file[i]);
	else if (execve(x->file[i], x->vec[i], envp) == ERROR)
		exit_child(x, END, NULL, NULL);
}
