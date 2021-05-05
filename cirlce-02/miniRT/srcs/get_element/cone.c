/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:02:54 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 23:02:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_co(t_cone *co, int idx)
{
	ostream_title("Cone", idx);
	ostream_vector(&(co->p), "Cone Position\t\t");
	ostream_vector(&(co->o), "Cone Orientation\t");
	ostream_floating_point(co->a, "Cone Angle\t\t");
	ostream_floating_point(co->h, "Cone Height\t\t");
	ostream_color(&(co->c), "Cone Color\t\t");
	printf("\n");
}

static t_bool	valid_co(t_cone *co, int idx)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(co->o))
		ret = FALSE;
	if (co->a <= 0.0 || co->a >= 90.0)
		ret = FALSE;
	if (!valid_color(co->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid cone value\n", 27);
	to_string_co(co, idx + 1);
	return (ret);
}

static t_bool	parse_co(t_cone *co, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(co->p.x), &(co->p.y), &(co->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(co->o.x), &(co->o.y), &(co->o.z)))
		ret = FALSE;
	if (!udouble(&line, &(co->a)))
		ret = FALSE;
	if (!udouble(&line, &(co->h)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing cone\n", 27);
	else
		co->c = c_init(r, g, b);
	return (ret);
}

t_bool			get_cone(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_co(&((rt->co)[i]), line) || !valid_co(&((rt->co)[i]), i))
		return (FALSE);
	(rt->co)[i].a = degrees_to_radians((rt->co)[i].a);
	++i;
	return (TRUE);
}

t_bool			chk_cone(t_scene *rt)
{
	++(rt->cnt.co);
	++(rt->cnt.obj);
	return (TRUE);
}
