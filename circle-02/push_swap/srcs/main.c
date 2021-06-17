/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:50:48 by jseo             ###   ########.fr       */
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

int				main(int ac, char **av)
{
	t_set	*s;
	t_ps	*ps;

	s = NULL;
	ps = NULL;
	if (ac == 1)
		exit_valid(&ps);
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps)) && check(ac, av, &s, &ps)))
		exit_invalid(&ps);
	prerequisite(&ps);
	if (ps->al > 2)
		yield(&ps);
	print_stacks(&ps);
	exit_valid(&ps);
}
