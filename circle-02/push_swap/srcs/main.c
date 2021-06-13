/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/13 19:52:22 by jseo             ###   ########.fr       */
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
	bool	sorted;

	ps = NULL;
	sorted = true;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps))
			|| !args_check(argc, argv, &ps)
			|| !args_unique(&ps, &sorted))
		exit_invalid(&ps);
	else
	{
		if (!sorted)
		{
			jputstr("not sorted\n", STDOUT_FILENO);
			sol_yield(&ps);
			sol_optimize(&ps);
		}
		else
			jputstr("sorted\n", STDOUT_FILENO);
	}
	exit_valid(&ps);
}
