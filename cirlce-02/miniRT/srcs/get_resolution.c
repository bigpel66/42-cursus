/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 13:26:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_resolution(t_scene *rt)
{
	if (rt->r.w <= 0)
	{
		printf("Detail: Invalid resolution width\n");
		return (FALSE);
	}
	if (rt->r.h <= 0)
	{
		printf("Detail: Invalid resolution height\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_resolution(t_scene *rt, char *line)
{
	if (!vint(&line, &(rt->r.w)))
	{
		printf("Detail: Wrong parsing resolution width\n");
		return (FALSE);
	}
	if (!vint(&line, &(rt->r.h)))
	{
		printf("Detail: Wrong parsing resolution width\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_resolution(t_scene *rt, char *line)
{
	if (rt->r.f)
		return (FALSE);
	rt->r.f = TRUE;
	if (!parse_resolution(rt, line) || !valid_resolution(rt))
		return (FALSE);
	return (TRUE);
}
