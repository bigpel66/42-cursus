/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:39:46 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 18:07:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_set	*set;
	bool	debug;

	ps = NULL;
	set = NULL;
	debug = false;
	if (!jstrncmp(av[ac - 1], "--debug", jstrlen(av[ac - 1])))
		debug = true;
	if (debug)
		--ac;
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps))
		&& check(ac, av, &ps, &set)
		&& yield(&ps, debug)))
		exit_invalid(&ps, "KO\n");
	jputstr("OK", STDOUT_FILENO);
	exit_valid(&ps);
}
