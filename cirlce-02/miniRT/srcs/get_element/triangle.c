/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:55 by jseo              #+#    #+#             */
/*   Updated: 2021/05/02 21:57:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_tr(t_triangle *tr, int idx)
{
	ostream_title("Triangle", idx);
	ostream_vector(&(tr->p1), "Triangle Position 1\t");
	ostream_vector(&(tr->p2), "Triangle Position 2\t");
	ostream_vector(&(tr->p3), "Triangle Position 3\t");
	ostream_color(&(tr->c), "Triangle Color\t");
	ostream_vector(&(tr->n), "Triangle Normal\t\t");
	printf("\n");
}

static t_bool	valid_tr(t_triangle *tr)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_color(tr->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid triangle value\n", 31);
	return (ret);
}

static t_bool	parse_tr(t_triangle *tr, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(tr->p1.x), &(tr->p1.y), &(tr->p1.z)))
		ret = FALSE;
	if (!sdouble(&line, &(tr->p2.x), &(tr->p2.y), &(tr->p2.z)))
		ret = FALSE;
	if (!sdouble(&line, &(tr->p3.x), &(tr->p3.y), &(tr->p3.z)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing triangle\n", 31);
	else
		tr->c = c_init(r, g, b);
	return (ret);
}

t_bool			get_triangle(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_tr(&((rt->tr)[i]), line) || !valid_tr(&((rt->tr)[i])))
		return (FALSE);
	(rt->tr)[i].p = (rt->tr)[i].p1;
	(rt->tr)[i].n = unit(cross(sub((rt->tr)[i].p2, (rt->tr)[i].p1),
								sub((rt->tr)[i].p3, (rt->tr)[i].p1)));
	to_string_tr(&((rt->tr)[i]), i + 1);
	++i;
	return (TRUE);
}

t_bool			chk_triangle(t_scene *rt)
{
	++(rt->cnt.tr);
	++(rt->cnt.obj);
	return (TRUE);
}
