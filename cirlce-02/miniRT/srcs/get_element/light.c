/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:36 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_l(t_light *l, int idx)
{
	ostream_title("Light", idx);
	ostream_vector(&(l->p), "Light Position\t\t");
	ostream_floating_point(l->s, "Light Ratio\t\t");
	ostream_color(&(l->c), "Light N Color\t\t");
	printf("\n");
}

static t_bool	valid_l(t_light *l, int idx)
{
	t_bool	ret;

	ret = TRUE;
	if (l->s < 0.0 || l->s > 1.0)
		ret = FALSE;
	if (!valid_color(l->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid light value\n", 28);
	to_string_l(l, idx + 1);
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
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing light\n", 28);
	return (ret);
}

t_bool			get_light(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_l(&((rt->l)[i]), line) || !valid_l(&((rt->l)[i]), i))
		return (FALSE);
	++i;
	return (TRUE);
}

t_bool			chk_light(t_scene *rt)
{
	++(rt->cnt.l);
	return (TRUE);
}
