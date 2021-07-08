/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 00:10:29 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 11:20:20 by jseo             ###   ########.fr       */
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
	int		i;

	if (!x)
		return ;
	i = -1;
	while (++i < x->cnt * 2)
		if (x->p[i])
			close(x->p[i]);
	jfree((void **)(&(x->p)));
	free_path(x);
	free_file(x);
	free_vec(x);
}
