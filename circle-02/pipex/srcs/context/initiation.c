/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:44:53 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 19:59:13 by jseo             ###   ########.fr       */
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

static void	parse_stdin(char *limiter, t_arg *x)
{
	;
}

static void	parse_command(char *cmd, t_arg *x)
{
	printf("%sc\n", cmd);
}

void	init(int ac, char **av, t_arg *x)
{
	int	i;

	i = 1;
	if (!prepare(x, ac - 2))
		exit_invalid(x, false, "");
	if (x->heredoc)
		parse_stdin(av[i], x);
	else
		x->in = av[i];
	while (++i < ac - 1)
		parse_command(av[i], x);
	x->out = av[i];
}
