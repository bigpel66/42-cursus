/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:34:51 by jseo              #+#    #+#             */
/*   Updated: 2021/07/06 00:35:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_command(t_arg *x, int i)
{
	int	j;

	j = -1;
	while (x->av[i][++j])
		printf("init\t%s\n", x->av[i][j]);
	return (true);
}

bool	parse_command(t_arg *x, const char *cmd, int i)
{
	x->av[i] = jsplit(cmd);
	if (!(x->av[i]))
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
