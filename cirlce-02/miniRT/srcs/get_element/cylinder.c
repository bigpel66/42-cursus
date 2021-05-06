/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:32 by jseo              #+#    #+#             */
/*   Updated: 2021/05/03 23:53:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_cy(t_cylinder *cy, int idx)
{
	ostream_title("Cylinder", idx);
	ostream_vector(&(cy->p), "Cylinder Position\t");
	ostream_vector(&(cy->o), "Cylinder Orientation\t");
	ostream_floating_point(cy->d, "Cylinder Diameter\t");
	ostream_floating_point(cy->h, "Cylinder Height\t\t");
	ostream_color(&(cy->c), "Cylinder Color\t");
	ostream_floating_point(cy->r, "Cylinder Radius\t\t");
	ostream_vector(&(cy->tc), "Cylinder Top Center\t");
	ostream_vector(&(cy->bc), "Cylinder Bottom Center\t");
	printf("\n");
}

static t_bool	valid_cy(t_cylinder *cy)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(cy->o))
		ret = FALSE;
	if (cy->d <= 0.0)
		ret = FALSE;
	if (cy->h <= 0.0)
		ret = FALSE;
	if (!valid_color(cy->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid cylinder value\n", 31);
	return (ret);
}

static t_bool	parse_cy(t_cylinder *cy, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(cy->p.x), &(cy->p.y), &(cy->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(cy->o.x), &(cy->o.y), &(cy->o.z)))
		ret = FALSE;
	if (!udouble(&line, &(cy->d)))
		ret = FALSE;
	if (!udouble(&line, &(cy->h)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing cylinder\n", 31);
	else
		cy->c = c_init(r, g, b);
	return (ret);
}

t_bool			get_cylinder(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_cy(&((rt->cy)[i]), line) || !valid_cy(&((rt->cy)[i])))
		return (FALSE);
	(rt->cy)[i].r = (rt->cy)[i].d / 2;
	(rt->cy)[i].tc = add((rt->cy)[i].p,
							scale((rt->cy)[i].o, (rt->cy)[i].h / 2));
	(rt->cy)[i].bc = sub((rt->cy)[i].p,
							scale((rt->cy)[i].o, (rt->cy)[i].h / 2));
	to_string_cy(&((rt->cy)[i]), i + 1);
	++i;
	return (TRUE);
}

t_bool			chk_cylinder(t_scene *rt)
{
	++(rt->cnt.cy);
	++(rt->cnt.obj);
	return (TRUE);
}
