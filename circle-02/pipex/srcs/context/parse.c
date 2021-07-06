/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:34:51 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 00:52:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_command(t_arg *x, int i)
{
	int		j;
	char	*corr;
	char	*file;

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
	file = jstrdup(x->vec[i][0]);
	if (!access(file, F_OK))
	{
		x->file[i] = file;
		return (true);
	}
	jfree((void **)(&file));
	return (false);
}

bool	parse_command(t_arg *x, const char *cmd, int i)
{
	x->vec[i] = jsplit(cmd, jisspace);
	if (!(x->vec[i]))
		return (false);
	return (true);
}

bool	check_infile(t_arg *x)
{
	return (true);
}

bool	parse_stdin(t_arg *x)
{
	return (true);
}
