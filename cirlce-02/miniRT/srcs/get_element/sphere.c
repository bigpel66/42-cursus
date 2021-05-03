/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:23:43 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:24:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_sp(t_sphere *sp, int idx)
{
	ostream_title("Sphere", idx);
	ostream_vector(&(sp->p), "Sphere Position\t\t");
	ostream_floating_point(sp->d, "Sphere Diameter\t\t");
	ostream_color(&(sp->c), "Sphere N Color\t\t");
	printf("\n");
}

static t_bool	valid_sp(t_sphere *sp, int idx)
{
	t_bool	ret;

	ret = TRUE;
	if (sp->d <= 0.0)
		ret = FALSE;
	if (!valid_color(sp->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid sphere value\n", 29);
	to_string_sp(sp, idx + 1);
	return (ret);
}

static t_bool	parse_sp(t_sphere *sp, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(sp->p.x), &(sp->p.y), &(sp->p.z)))
		ret = FALSE;
	if (!udouble(&line, &(sp->d)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	sp->c = c_init(r, g, b);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing sphere\n", 29);
	return (ret);
}

t_bool			get_sphere(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_sp(&((rt->sp)[i]), line) || !valid_sp(&((rt->sp)[i]), i))
		return (FALSE);
	(rt->sp)[i].r = (rt->sp)[i].d / 2;
	ostream_floating_point((rt->sp)[i].r, "Sphere Radius\t\t");
	printf("\n");
	++i;
	return (TRUE);
}

t_bool			chk_sphere(t_scene *rt)
{
	++(rt->cnt.sp);
	return (TRUE);
}
