/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:47:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 19:24:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	shift(int *ac, char **av)
{
	int		i;

	i = 0;
	while (++i < *ac - 1)
		av[i] = av[i + 1];
	av[i] = NULL;
	--(*ac);
}

int	main(int ac, char **av)
{
	const char	*s = "usage: ./pipex [here_doc] infile cmd1 cmd2 ... outfile\n";
	t_arg		x;

	jmemset(&x, 0, sizeof(t_arg));
	if (ac > 1 && !jstrncmp(av[1], "here_doc", jstrlen("here_doc")))
	{
		x.heredoc = true;
		shift(&ac, av);
	}
	if (ac < 5)
		exit_invalid(NULL, true, s);
	init(ac, av, &x);
	exec(&x);
	exit_valid(&x);
}
