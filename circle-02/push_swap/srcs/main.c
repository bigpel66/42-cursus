/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:58:57 by jseo             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps))
			|| !args_check(argc, argv, &ps)
			|| !args_unique(&ps))
		exit_invalid(&ps);
	else
	{
		if (!args_sorted(&ps))
		{
			sol_yield();
			sol_optimize();
		}
	}
	exit_valid(&ps);
}
