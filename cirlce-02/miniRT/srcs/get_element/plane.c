/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:39 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_pl(t_plane *pl, int idx)
{
	ostream_title("Plane", idx);
	ostream_vector(&(pl->p), "Plane Position\t\t");
	ostream_vector(&(pl->n), "Plane Normal\t\t");
	ostream_color(&(pl->c), "Plane Color\t\t");
	printf("\n");
}

static t_bool	valid_pl(t_plane *pl)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(pl->n))
		ret = FALSE;
	if (!valid_color(pl->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid plane value\n", 28);
	return (ret);
}

static t_bool	parse_pl(t_plane *pl, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(pl->p.x), &(pl->p.y), &(pl->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(pl->n.x), &(pl->n.y), &(pl->n.z)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing plane\n", 28);
	else
		pl->c = c_init(r, g, b);
	return (ret);
}

t_bool			get_plane(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_pl(&((rt->pl)[i]), line) || !valid_pl(&((rt->pl)[i])))
		return (FALSE);
	to_string_pl(&((rt->pl)[i]), i + 1);
	++i;
	return (TRUE);
}

t_bool			chk_plane(t_scene *rt)
{
	++(rt->cnt.pl);
	++(rt->cnt.obj);
	return (TRUE);
}
