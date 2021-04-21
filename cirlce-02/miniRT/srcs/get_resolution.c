/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:00:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		resolution_to_string(t_scene *rt)
{
	ostream_integer(rt->r.w, "Resolution Width");
	ostream_integer(rt->r.h, "Resolution Height");
}

static t_bool	valid_resolution(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->r.w <= 0)
		ret = FALSE;
	if (rt->r.h <= 0)
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid resolution value\n");
	return (ret);
}

static t_bool	parse_resolution(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!uint(&line, &(rt->r.w)))
		ret = FALSE;
	if (!uint(&line, &(rt->r.h)))
		ret = FALSE;
	resolution_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on resolution\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing resolution\n");
	return (ret);
}

t_bool			get_resolution(t_scene *rt, char *line)
{
	if (!parse_resolution(rt, line) || !valid_resolution(rt))
		return (FALSE);
	return (TRUE);
}
