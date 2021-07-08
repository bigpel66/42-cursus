/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:18:27 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 20:25:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	const char	*s = "usage: ./pipex inflie cmd1 cmd2 outfile\n";
	t_arg		x;

	jmemset(&x, 0, sizeof(t_arg));
	if (argc != 5)
		exit_invalid(NULL, true, s, "");
	if (!path(envp, &x))
		exit_invalid(&x, true, "invalid envp\n", "");
	init(argc, argv, &x);
	process(envp, &x);
	exit_valid(&x);
}
