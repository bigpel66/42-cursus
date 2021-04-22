/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:39 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:47:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_pl(t_plane *pl, int idx)
{
	print_title("Plane", idx);
	ostream_vector(&(pl->p), "Plane Position\t\t");
	ostream_vector(&(pl->o), "Plane Orientation\t");
	ostream_color(&(pl->c), "Plane Color\t\t");
	printf("\n");
}

static t_bool	valid_pl(t_plane *pl)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(pl->o))
		ret = FALSE;
	if (!valid_color(pl->c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid plane value\n");
	return (ret);
}

static t_bool	parse_pl(t_plane *pl, char *line, int idx)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(pl->p.x), &(pl->p.y), &(pl->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(pl->o.x), &(pl->o.y), &(pl->o.z)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	c_init(&(pl->c), r, g, b);
	to_string_pl(pl, idx + 1);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		printf("Detail: Wrong parsing plane\n");
	return (ret);
}

t_bool			get_plane(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_pl(&((rt->pl)[i]), line, i) || !valid_pl(&((rt->pl)[i])))
		return (FALSE);
	++i;
	return (TRUE);
}
