/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:47:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/06 00:30:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	shift(int *ac, char **av, t_arg *x)
{
	int		i;

	i = 1;
	x->heredoc = true;
	x->limiter = av[i];
	while (++i < *ac)
		av[i - 1] = av[i];
	--(*ac);
	av[*ac] = NULL;
}

int	main(int ac, char **av)
{
	const char	*s = "usage: ./pipex [here_doc] infile cmd1 cmd2 ... outfile\n";
	t_arg		x;

	jmemset(&x, 0, sizeof(t_arg));
	if (ac > 1 && !jstrncmp(av[1], "here_doc", jstrlen("here_doc")))
		shift(&ac, av, &x);
	if (ac < 5)
		exit_invalid(NULL, true, s, "");
	init(ac, av, &x);
	exec(&x);
	exit_valid(&x);
}
