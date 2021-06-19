/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/18 12:36:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This is the instruction test
** Paste one of those into the "else" phrase
**
** test_push(&ps);
** test_rotate(&ps);
** test_rrotate(&ps);
** test_swap(&ps);
*/

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_set	*set;
	t_base	*base;

	ps = NULL;
	set = NULL;
	base = NULL;
	if (ac == 1)
		exit_valid(&ps, &base);
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps))
		&& jcalloc((void **)(&base), 1, sizeof(t_base))
		&& check(ac, av, &ps, &set)))
		exit_invalid(&ps, &base);
	prerequisite(&ps, base);
	if (ps->al > 2)
		yield(&ps, base);
	exit_valid(&ps, &base);
}
