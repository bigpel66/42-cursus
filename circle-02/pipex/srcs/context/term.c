/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/10 13:19:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_child(t_arg *x, int code)
{
	free_arg(x);
	exit(code);
}

void	exit_parent(t_arg *x, int code, int i)
{
	int		j;
	bool	mode;

	j = -1;
	mode = false;
	if (code == EACCES)
		exit_invalid(x, true, "permission denied: ", x->file[i]);
	else if (code == ENOENT)
	{
		if (!access(x->file[i], F_OK))
			return ;
		while (x->file[i][++j])
			if (x->file[i][j] == '/')
				mode = true;
		if (mode)
			exit_invalid(x, true, "no such file or directory: ", x->file[i]);
		else
			exit_invalid(x, true, "command not found: ", x->file[i]);
	}
	errno = code;
	exit_invalid(x, false, "", "");
}

void	exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2)
{
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
