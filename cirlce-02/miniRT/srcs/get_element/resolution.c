/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		resolution_to_string(t_scene *rt, int idx)
{
	print_title("Resolution", idx);
	printf("%s%d\n", "Resolution Width\t\t", rt->r.w);
	printf("%s%d\n", "Resolution Height\t\t", rt->r.h);
	printf("\n");
}

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
	resolution_to_string(rt, 0);
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
