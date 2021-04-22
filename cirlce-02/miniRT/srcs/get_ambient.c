/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:46:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ambient_to_string(t_scene *rt, int idx)
{
	print_title("Ambient", idx);
	ostream_floating_point(rt->a.s, "Ambient Ratio\t\t");
	ostream_color(&(rt->a.c), "Ambient Color\t\t");
	printf("\n");
}

static t_bool	valid_ambient(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->a.s < 0.0 || rt->a.s > 1.0)
		ret = FALSE;
	if (!valid_color(rt->a.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid ambient value\n");
	return (ret);
}

static t_bool	parse_ambient(t_scene *rt, char *line)
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
	c_init(&(rt->a.c), r, g, b);
	ambient_to_string(rt, 0);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		printf("Detail: Wrong parsing ambient\n");
	return (ret);
}

t_bool			get_ambient(t_scene *rt, char *line)
{
	if (!parse_ambient(rt, line) || !valid_ambient(rt))
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
		printf("Detail: Ambient is not unique\n");
		return (FALSE);
	}
}
