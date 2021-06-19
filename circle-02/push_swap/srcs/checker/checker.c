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

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_set	*set;

	ps = NULL;
	set = NULL;
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps))
		&& check(ac, av, &ps, &set)
		&& yield(&ps)))
		exit_invalid(&ps, "KO\n");
	jputstr("OK", STDOUT_FILENO);
	exit_valid(&ps);
}
