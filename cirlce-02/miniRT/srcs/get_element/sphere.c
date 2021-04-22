/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:47:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_sp(t_sphere *sp, int idx)
{
	print_title("Sphere", idx);
	ostream_vector(&(sp->p), "Sphere Position\t\t");
	ostream_floating_point(sp->d, "Sphere Diameter\t\t");
	ostream_color(&(sp->c), "Sphere Color\t\t");
	printf("\n");
}

static t_bool	valid_sp(t_sphere *sp)
{
	t_bool	ret;

	ret = TRUE;
	if (sp->d <= 0.0)
		ret = FALSE;
	if (!valid_color(sp->c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid sphere value\n");
	return (ret);
}

static t_bool	parse_sp(t_sphere *sp, char *line, int idx)
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
	c_init(&(sp->c), r, g, b);
	to_string_sp(sp, idx + 1);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		printf("Detail: Wrong parsing sphere\n");
	return (ret);
}

t_bool			get_sphere(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_sp(&((rt->sp)[i]), line, i) || !valid_sp(&((rt->sp)[i])))
		return (FALSE);
	++i;
	return (TRUE);
}

t_bool			chk_sphere(t_scene *rt)
{
	++(rt->cnt.sp);
	return (TRUE);
}
