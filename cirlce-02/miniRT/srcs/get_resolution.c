/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_resolution(t_mlx *m)
{
	if (m->i.r.w <= 0)
	{
		printf("Detail: Occured on resolution width\n");
		return (FALSE);
	}
	if (m->i.r.h <= 0)
	{
		printf("Detail: Occured on resolution height\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_resolution(t_mlx *m, char *line)
{
	if (m->i.r.f)
		return (FALSE);
	m->i.r.f = TRUE;
	m->i.r.w = vint(&line);
	m->i.r.h = vint(&line);
	if (!valid_resolution(m))
		return (FALSE);
	return (TRUE);
}
