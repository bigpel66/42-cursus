/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/06 00:36:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	prepare(t_arg *x, int cnt)
{
	if (pipe(x->p) == ERROR)
		return (false);
	if (!jcalloc((void **)(&(x->av)), cnt, sizeof(char **)))
		return (false);
	return (true);
}

void	init(int ac, char **av, t_arg *x)
{
	int	i;

	i = 1;
	if (!prepare(x, ac - 2))
		exit_invalid(x, false, "", "");
	if (x->heredoc)
		if (!parse_stdin(x))
			exit_invalid(x, false, "", "");
	if (!(x->heredoc))
		if (!check_infile(x))
			exit_invalid(x, true, "no such file or directory: ", x->in);
	while (++i < ac - 1)
	{
		if (!parse_command(x, av[i], i - 2))
			exit_invalid(x, false, "", "");
		if (!check_command(x, i - 2))
			exit_invalid(x, true, "command not found: ", x->av[i][0]);
	}
	x->out = av[i];
}
