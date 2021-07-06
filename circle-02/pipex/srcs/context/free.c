/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 00:10:29 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 00:23:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_path(t_arg *x)
{
	int	i;

	i = -1;
	while (x->path[++i])
		jfree((void **)(&(x->path[i])));
	jfree((void **)(&(x->path)));
}

static void	free_file(t_arg *x)
{
	int	i;

	i = -1;
	while (x->file[++i])
		jfree((void **)(&(x->file[i])));
	jfree((void **)(&(x->file)));
}

static void	free_vec(t_arg *x)
{
	int		i;
	int		j;

	i = -1;
	while (x->vec[++i])
	{
		j = -1;
		while (x->vec[i][++j])
			jfree((void **)(&(x->vec[i][j])));
		jfree((void **)(&(x->vec[i])));
	}
	jfree((void **)(&(x->vec)));
}

void	free_arg(t_arg *x)
{
	if (!x)
		return ;
	if ((x->p[P_READ]))
		close(x->p[P_READ]);
	if (x->p[P_WRITE])
		close(x->p[P_WRITE]);
	if (x->heredoc)
		jfree((void **)(&(x->in)));
	free_path(x);
	free_file(x);
	free_vec(x);
}
