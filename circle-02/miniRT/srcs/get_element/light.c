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

static t_bool	valid_l(t_light *l)
{
	t_bool	ret;

	ret = TRUE;
	if (l->s < 0.0 || l->s > 1.0)
		ret = FALSE;
	if (!valid_color(l->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid light value\n", 28);
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
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing light\n", 28);
	else
		l->c = c_init(r, g, b);
	return (ret);
}

t_bool			get_light(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_l(&((rt->l)[i]), line) || !valid_l(&((rt->l)[i])))
		return (FALSE);
	to_string_l(&((rt->l)[i]), i + 1);
	++i;
	return (TRUE);
}

t_bool			chk_light(t_scene *rt)
{
	++(rt->cnt.l);
	return (TRUE);
}
