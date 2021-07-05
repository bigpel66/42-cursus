/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 17:32:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arg(t_arg *x)
{
	void	**tmp;

	if (!x)
		return ;
	tmp = (void **)(&(x->av));
	if ((x->p[P_READ]))
		close(x->p[P_READ]);
	if (x->p[P_WRITE])
		close(x->p[P_WRITE]);
	while (x->av)
	{
		while (*(x->av))
		{
			jfree((void **)((*(x->av))));
			++(*(x->av));
		}
		jfree((void **)(x->av));
		++(x->av);
	}
	jfree(tmp);
}

void	exit_invalid(t_arg *x, bool custom, char *s)
{
	if (custom)
		write(STDERR_FILENO, s, jstrlen(s));
	else
		strerror(errno);
	free_arg(x);
	exit(INVALID);
}

void	exit_valid(t_arg *x)
{
	free_arg(x);
	exit(VALID);
}
