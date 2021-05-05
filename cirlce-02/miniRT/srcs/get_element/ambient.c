/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ambient_to_string(t_scene *rt, int idx)
{
	ostream_title("Ambient", idx);
	ostream_floating_point(rt->a.s, "Ambient Ratio\t\t");
	ostream_color(&(rt->a.c), "Ambient Color\t\t");
	printf("\n");
}

static t_bool	valid_a(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->a.s < 0.0 || rt->a.s > 1.0)
		ret = FALSE;
	if (!valid_color(rt->a.c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid ambient value\n", 30);
	ambient_to_string(rt, 0);
	return (ret);
}

static t_bool	parse_a(t_scene *rt, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!udouble(&line, &(rt->a.s)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing ambient\n", 30);
	else
		rt->a.c = c_init(r, g, b);
	return (ret);
}

t_bool			get_ambient(t_scene *rt, char *line)
{
	if (!parse_a(rt, line) || !valid_a(rt))
		return (FALSE);
	return (TRUE);
}

t_bool			chk_ambient(t_scene *rt)
{
	++(rt->cnt.a);
	if (rt->cnt.a == 1)
		return (TRUE);
	else
	{
		write(STDERR_FILENO, "Detail: Ambient is not unique\n", 30);
		return (FALSE);
	}
}
