/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:47:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 17:28:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	shift(int *argc, char **argv, t_arg *x)
{
	int		i;

	i = 1;
	while (++i < *argc)
		argv[i - 1] = argv[i];
	--(*argc);
	argv[*argc] = NULL;
	x->heredoc = true;
	x->limiter = argv[1];
}

int	main(int argc, char **argv, char **envp)
{
	const char	*s = "usage: ./pipex [here_doc] infile cmd1 cmd2 ... outfile";
	t_arg		x;

	jmemset(&x, 0, sizeof(t_arg));
	if (argc > 1 && !jstrncmp(argv[1], "here_doc", jstrlen("here_doc")))
		shift(&argc, argv, &x);
	if (argc < 5)
		exit_invalid(NULL, true, s, "");
	init(argc, argv, envp, &x);
	exec(envp, &x);
	exit_valid(&x);
}
