/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:40:27 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 16:10:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	chunk(t_arg *x, const char *cmd, int i)
{
	int		j;
	bool	mode;

	j = -1;
	mode = false;
	while (cmd[++j])
	{
		if (s_quote(cmd[j]) || d_quote(cmd[j]))
			mode = true;
		if (cmd[j + 1])
			if (es_quote(cmd[j], cmd[j + 1]) || ed_quote(cmd[j], cmd[j + 1]))
				mode = true;
	}
	if (mode)
		x->vec[i] = qsplit(cmd);
	else
		x->vec[i] = jsplit(cmd, jisspace);
	if (!(x->vec[i]))
		return (false);
	return (true);
}

bool	command(t_arg *x, const char *cmd, int i)
{
	int		j;
	char	*corr;
	char	*file;

	if (!chunk(x, cmd, i))
		return (false);
	j = -1;
	while (x->path[++j])
	{
		corr = jstrjoin(x->path[j], "/");
		file = jstrjoin(corr, x->vec[i][0]);
		jfree((void **)(&corr));
		if (!access(file, F_OK))
		{
			x->file[i] = file;
			return (true);
		}
		jfree((void **)(&file));
	}
	x->file[i] = jstrdup(x->vec[i][0]);
	if (!(x->file[i]))
		return (false);
	return (true);
}
