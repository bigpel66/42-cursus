/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:36 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:00:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_l(t_light *l)
{
	ostream_vector(&(l->p), "Light Position");
	ostream_floating_point(l->s, "Light Ratio");
	ostream_color(&(l->c), "Light Color");
}

static t_bool	valid_l(t_light *l)
{
	t_bool	ret;

	ret = TRUE;
	if (l->s < 0.0 || l->s > 1.0)
		ret = FALSE;
	if (!valid_color(l->c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid light value\n");
	return (ret);
}

static t_bool	parse_l(t_light *l, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(l->p.x), &(l->p.y), &(l->p.z)))
		ret = FALSE;
	if (!udouble(&line, &(l->s)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	c_init(&(l->c), r, g, b);
	to_string_l(l);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		printf("Detail: Wrong parsing light\n");
	return (ret);
}

t_bool			get_light(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_l(&((rt->l)[i]), line) || !valid_l(&((rt->l)[i])))
		return (FALSE);
	++i;
	return (TRUE);
}
