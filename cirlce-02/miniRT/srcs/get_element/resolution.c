/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 22:59:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_r(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->r.w <= 0)
		ret = FALSE;
	if (rt->r.h <= 0)
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid resolution value\n", 33);
	if (rt->r.w > 0 && rt->r.h > 0)
	{
		if (rt->r.w > RES_X || rt->r.h < RES_Y)
			printf("Warning: Resolution has been fitted to the max\n");
		rt->r.w = (int)clamp(rt->r.w, 0.0, (double)RES_X);
		rt->r.h = (int)clamp(rt->r.h, 0.0, (double)RES_Y);
	}
	rt->r.ar = (double)rt->r.w / (double)rt->r.h;
	return (ret);
}

static t_bool	parse_r(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!uint(&line, &(rt->r.w)))
		ret = FALSE;
	if (!uint(&line, &(rt->r.h)))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing resolution\n", 33);
	return (ret);
}

t_bool			get_resolution(t_scene *rt, char *line)
{
	if (!parse_r(rt, line) || !valid_r(rt))
		return (FALSE);
	to_string_r(rt, 0);
	return (TRUE);
}

t_bool			chk_resolution(t_scene *rt)
{
	++(rt->cnt.r);
	if (rt->cnt.r == 1)
		return (TRUE);
	else
	{
		write(STDERR_FILENO, "Detail: Resolution is not unique\n", 33);
		return (FALSE);
	}
}
