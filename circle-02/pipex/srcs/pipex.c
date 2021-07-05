/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:18:27 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 17:44:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	const char	*s = "usage: ./pipex inflie cmd1 cmd2 outfile\n";
	t_arg		x;

	jmemset(&x, 0, sizeof(t_arg));
	if (ac != 5)
		exit_invalid(NULL, true, s);
	parse(&x);
	command(&x);
	exit_valid(&x);
}
