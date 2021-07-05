/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/06 00:16:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arg(t_arg *x)
{
	int		i;
	int		j;

	if (!x)
		return ;
	if ((x->p[P_READ]))
		close(x->p[P_READ]);
	if (x->p[P_WRITE])
		close(x->p[P_WRITE]);
	if (x->heredoc)
		jfree((void **)(&(x->in)));
	i = 0;
	while (x->av[i])
	{
		j = 0;
		while (x->av[i][j])
		{
			jfree((void **)(&(x->av[i][j])));
			++j;
		}
		jfree((void **)(&(x->av[i])));
		++i;
	}
	jfree((void **)(&(x->av)));
}

void	exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2)
{
	if (custom)
	{
		write(STDERR_FILENO, s1, jstrlen(s1));
		write(STDERR_FILENO, s2, jstrlen(s2));
	}
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
