/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 16:48:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			// instruction_generate();
			// instruction_optimize();
		}
		else
			printf("sorted\n");
	}
	exit_valid(&ps);
}
