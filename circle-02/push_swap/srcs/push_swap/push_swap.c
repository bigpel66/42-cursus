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

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_set	*set;

	ps = NULL;
	set = NULL;
	if (ac == 1)
		exit_valid(&ps);
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps))
		&& check(ac, av, &ps, &set)))
		exit_invalid(&ps, "Error\n");
	yield(&ps);
	exit_valid(&ps);
}
